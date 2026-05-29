#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            for(int i=0;i<nums1.size();i++){
                for(int j=0;j<nums2.size();j++){
                    if(nums1[i]==nums2[j]){
                        ans.push_back(nums1[i]);
                    }
                }
            }
        }
        if(nums2.size()>nums1.size()){
            for(int i=0;i<nums2.size();i++){
                for(int j=0;j<nums1.size();j++){
                    if(nums2[i]==nums1[j]){
                        ans.push_back(nums2[i]);
                    }
                }
            }
        }
        removeDuplicates(ans);
        return ans;
        
    }
private:    
    void removeDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    vector<int> result;

    for (int x : nums) {
        if (seen.insert(x).second) {
            result.push_back(x);
        }
    }
    nums = result;
    }
};