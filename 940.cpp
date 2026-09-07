#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int distinctSubseqII(string s) {
        const long long mod=1000000007;
        long long dp=1;
        vector<long long> last(26,0);
        for(char c:s){
            int indx=c-'a';
            long long oldDP=dp;
            dp=(2*dp-last[indx]+mod)%mod;
            last[indx]=oldDP;
        }
        return (dp-1+mod)%mod;
    }
};