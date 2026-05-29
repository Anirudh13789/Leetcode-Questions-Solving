#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // STEP 1: Convert digits to number
        long long num = 0;   // use long long (still unsafe for very large input)
        for (int i = 0; i < n; i++) {
            num = num * 10 + digits[i];
        }

        // STEP 2: Add 1
        num = num + 1;

        // STEP 3: Convert number back to digits
        vector<int> result;
        if (num == 0) {
            result.push_back(0);
        }

        while (num > 0) {
            result.push_back(num % 10);
            num /= 10;
        }

        // STEP 4: Reverse result
        reverse(result.begin(), result.end());

        return result;
    }
};

