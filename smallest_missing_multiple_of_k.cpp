#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=1;i<=nums.size()+1;i++){
            int digit=k*i;
            if(freq[digit]==0){
                return digit;
            }
        }
        return -1;
    }
};