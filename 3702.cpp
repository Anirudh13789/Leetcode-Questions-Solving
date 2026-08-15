#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int totalXOR=0;
        bool hasNonZero=false;
        for(int x : nums){
            totalXOR=totalXOR^x;
            if(x!=0){
                hasNonZero=true;
            }
        }
        if(totalXOR!=0){
            return n;
        }
        if(hasNonZero){
            return n-1;
        }
        return 0;
    }
};