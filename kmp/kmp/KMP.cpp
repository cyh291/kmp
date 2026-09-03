#include "KMP.h"

void KMP::buildNext() {
    int m = (int)pattern.size();
    next.resize(m);
    next[0] = -1;

    int i = 0, j = -1;
    while (i < m - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}

KMP::KMP() {
    text = "";
    pattern = "";
}

KMP::KMP(const string& t, const string& p) {
    text = t;
    pattern = p;
    buildNext();
}

void KMP::setText(const string& t) {
    text = t;
}

void KMP::setPattern(const string& p) {
    pattern = p;
    buildNext();
}

int KMP::search() {
    if (text.empty() || pattern.empty()) {
        return -1;
    }

    int n = (int)text.size();
    int m = (int)pattern.size();
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];
        }
    }

    if (j == m) {
        return i - j;
    }
    return -1;
}

vector<int> KMP::searchAll() {
    vector<int> results;
    if (text.empty() || pattern.empty()) {
        return results;
    }

    int n = (int)text.size();
    int m = (int)pattern.size();
    int i = 0, j = 0;

    while (i < n) {
        if (j == -1 || text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                results.push_back(i - j);
                j = next[j - 1] + 1;
            }
        }
        else {
            j = next[j];
        }
    }
    return results;
}

void KMP::printNext() {
    cout << "Next array: ";
    for (int v : next) {
        cout << v << " ";
    }
    cout << endl;
}

// ===== 新增：带计时的搜索方法 =====
pair<int, long long> KMP::searchWithTime() {
    auto start = high_resolution_clock::now();   // 计时开始
    int pos = search();                          // 执行搜索
    auto end = high_resolution_clock::now();     // 计时结束
    auto duration = duration_cast<microseconds>(end - start).count();
    return { pos, duration };                      // 返回位置和耗时
}





void KMP::printResult(int pos) {
    if (pos == -1) {
        cout << "[X] Pattern not found" << endl;
        return;
    }

    cout << "[OK] Found at position: " << pos << endl;
    cout << "Text:    " << text << endl;
    cout << "         ";
    for (int i = 0; i < pos; i++) {
        cout << " ";
    }
    cout << pattern << endl;
}

void KMP::printAllResults(const vector<int>& positions) {
    if (positions.empty()) {
        cout << "[X] No matches found" << endl;
        return;
    }

    cout << "[OK] Total " << positions.size() << " match(es) found:" << endl;
    for (int pos : positions) {
        cout << "    Position " << pos << ": ";
        for (int i = 0; i < pos; i++) {
            cout << " ";
        }
        cout << pattern << endl;
    }
}
