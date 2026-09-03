#pragma once
#ifndef KMP_H
#define KMP_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

class KMP {
private:
    string text;
    string pattern;
    vector<int> next;

    void buildNext();

public:
    KMP();
    KMP(const string& t, const string& p);

    void setText(const string& t);
    void setPattern(const string& p);

    int search();
    vector<int> searchAll();

    void printNext();
    void printResult(int pos);
    void printAllResults(const vector<int>& positions);
    pair<int, long long> searchWithTime();
};

#endif