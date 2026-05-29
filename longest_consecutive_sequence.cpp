#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0){
            return 0;
        }
        int ans=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            //duplicates
            if(nums[i-1]==nums[i]){
                continue;
            }
            else if(nums[i-1]==nums[i]+1){
                curr++;
            }
            else{
                ans=max(ans,curr);
                curr=1;
            }
        }
        return max(ans,curr);
    }
};