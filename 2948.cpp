#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int start=0;
        for(int i=1;i<=n;i++){
            if(i==n || v[i].first-v[i-1].first>limit){
                vector<int> index;
                for(int j=start;j<i;j++){
                    index.push_back(v[j].second);
                }
                sort(index.begin(),index.end());
                for(int j=0;j<index.size();j++){
                    nums[index[j]]=v[start+j].first;
                }
                start=i;
            }
        }
        return nums;
    }
};