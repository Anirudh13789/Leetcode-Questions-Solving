#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int maximum_element=INT_MIN;
        int minimum_element=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maximum_element=max(maximum_element,nums[i]);
            minimum_element=min(minimum_element,nums[i]);
        }
        int count_minimum=0;
        int count_maximum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minimum_element){
                count_minimum++;
            }
            if(nums[i]==maximum_element){
                count_maximum++;
            }
        }
        if(count_maximum<=k*count_minimum){
            return 0;
        }
        else{
            return count_maximum-k*count_minimum;
        }
    }
};