#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minimum=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            minimum=min(minimum,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-minimum);
        }
        return ans;
    }
};