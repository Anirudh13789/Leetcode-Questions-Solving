#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maximum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maximum=max(maximum,nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(maximum-nums[i]);
        }
        return ans;
    }
};