#include <iostream>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.size() - 1;

        while (i >= 0) {
            // skip spaces
            while (i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;

            int j = i;
            // collect word
            while (i >= 0 && s[i] != ' ') i--;

            if (!res.empty()) res += " ";
            res += s.substr(i + 1, j - i);
        }
        return res;
    }
};
