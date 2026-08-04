#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]+1 != nums[i+1]){
                for(int j=nums[i]+1;j<nums[i+1];j++){
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};