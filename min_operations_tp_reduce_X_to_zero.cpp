#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int target=total-x;
        if(target<0){
            return -1;
        }
        if(target==0){
            return n;
        }
        int i=0;
        int sum=0;
        int longest=-1;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
                longest=max(longest,j-i+1);
            }
        }
        if(longest==-1){
            return -1;
        }
        return n-longest;

    }
};