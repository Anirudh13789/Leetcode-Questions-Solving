#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> keys = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;

    void phonekeypad(string &digits, string &op, int i) {
        // base case
        if (i == digits.size()) {
            ans.push_back(op);
            return;
        }

        int digit = digits[i] - '0';

        for (int k = 0; k < keys[digit].size(); k++) {
            op.push_back(keys[digit][k]);
            phonekeypad(digits, op, i + 1);
            op.pop_back(); // backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;

        string op = "";
        phonekeypad(digits, op, 0);
        return ans;
    }
};
