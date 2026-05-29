#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for(int i=0;i<nums.size()-3;i++){
            if(nums[i]<nums[i+1] and nums[i+1]<nums[i+2]){
                return true;
            }
        }
        return false;
    }
};