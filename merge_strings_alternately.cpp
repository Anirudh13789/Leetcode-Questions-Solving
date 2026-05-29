#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word3(word1.length() + word2.length(), ' ');
        int i1 = 0, i2 = 0;

        for (int i = 0; i < word3.length(); i++) {
            if (i % 2 == 0) {
                if (i1 < word1.length()) {
                    word3[i] = word1[i1++];
                } else {
                    word3[i] = word2[i2++];
                }
            } else {
                if (i2 < word2.length()) {
                    word3[i] = word2[i2++];
                } else {
                    word3[i] = word1[i1++];
                }
            }
        }
        return word3;
    }
};
