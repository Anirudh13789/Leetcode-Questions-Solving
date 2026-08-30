#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int highest=INT_MIN;
        int highest_indx;
        int lowest=INT_MAX;
        int lowest_indx;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>highest){
                highest=nums[i];
                highest_indx=i;
            }
            if(nums[i]<lowest){
                lowest=nums[i];
                lowest_indx=i;
            }
        }
        int cnt=0;
        int low=min(highest_indx,lowest_indx);
        int high=max(highest_indx,lowest_indx);
        int left=high+1;
        int right=nums.size()-low;
        int ans=low+1+nums.size()-high;
        return min(left,min(right,ans));
    }
};