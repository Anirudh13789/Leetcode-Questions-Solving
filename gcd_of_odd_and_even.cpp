#include <iostream>
#include <numeric>
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    } 
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        for(int i=1;i<=n;i=i+1){
            sumOdd+=(2*i-1);
        }
        int sumEven=0;
        for(int i=1;i<=n;i+=1){
            sumEven+=(2*i);
        }
        return gcd(sumOdd,sumEven);
    }
};