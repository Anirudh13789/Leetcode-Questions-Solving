#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> a(n);
        for(int i=0;i<nums.size();i++){
            a[i]=nums[i]*nums[i];
        }
        sort(a.begin(),a.end());
        int k=n/2;
        long long ans=0;
        for(int i=0;i<k;i++){
            ans-=a[i];
        }
        for(int i=k;i<n;i++){
            ans+=a[i];
        }
        return ans;
    }
};