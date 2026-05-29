#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftmax=nums[0];
        int currentmax=nums[0];
        int indx=0;

        for(int i=0;i<nums.size();i++){
            currentmax=max(currentmax,nums[i]);

            if(nums[i]<leftmax){
                leftmax=currentmax;
                indx=i;
            }
        }
        return indx+1;
    }
};