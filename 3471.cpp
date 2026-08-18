#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        for(auto &x: nums){
            freq[x]++;
        }
        int res=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(k==n || (freq[nums[i]]==1 && (k==1 || !i || i==n-1))){
                res=max(res,nums[i]);
            }
        }
        return res;
    }
};