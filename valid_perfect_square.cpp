#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int squareroot(int num) {
        for (long long i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return i;
            }
        }
        return -1;
    }

    bool isPerfectSquare(int num) {
        return squareroot(num) != -1;
    }
};
