#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<ans.size();i++){
            int count=0;
            for(int j=0;j<ans.size();j++){
                if(nums[j]<nums[i]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};