#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        return count;
    }
};