#include <iostream>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                num = num * 10 + d;
            }
            n /= 10;
        }
        long long rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        long long sum = 0;
        long long temp = rev;
        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        return rev * sum;
    }
};