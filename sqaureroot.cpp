#include <iostream>
using namespace std;
//newtons method
class Solution {
public:
    int mySqrt(int x) {
        long long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};

