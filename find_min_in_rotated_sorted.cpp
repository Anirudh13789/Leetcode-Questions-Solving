#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        int e=nums.size()-1;
        int mini=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            mini=min(mini,nums[mid]);
            if(nums[mid]<=nums[n-1]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return mini;
    }
};