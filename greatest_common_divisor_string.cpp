#include <iostream>
#include <numeric>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // If concatenation doesn't match, no GCD exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Find gcd of lengths
        int gcdLen = gcd(str1.length(), str2.length());

        // Return prefix of gcd length
        return str1.substr(0, gcdLen);
    }
};
