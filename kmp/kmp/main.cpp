#include "KMP.h"

int main() {
    cout << "========== Test 1: Basic match ==========" << endl;

    for (int j = 0; j < 5;j++) {

        string text;
        for (int i = 0;i < 500000;i++) {

            text += "AB";

        }

        string word1 = text + "C";

        KMP km1(word1, "ABABC");

        auto start = high_resolution_clock::now();

        int pos1 = km1.search();

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(end - start).count();


        cout << "Time taken: " << duration << " microseconds" << endl;
        cout << endl;



    }
	system("pause");
    return 0;
}
