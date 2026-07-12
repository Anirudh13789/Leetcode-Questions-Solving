#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;

        while(left<=right){
            if(nums[left]!=target){
                left++;
            }
            if(left<=right && nums[right]!=target){
                right--;
            }
            if(left<=right && nums[left]==target && nums[right]==target){
                return {left,right};
            }
        }
        return {-1,-1};
    }
};