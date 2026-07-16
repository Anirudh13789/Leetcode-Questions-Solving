#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int gcd(int a,int b){
        return b==0? a:gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int mx=INT_MIN;
        vector<int> prefixGCD(nums.size());
        for(int i=0;i<nums.size();i++){
            mx=max(nums[i],mx);
            prefixGCD[i]=gcd(nums[i],mx);
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        long long ans=0;
        int i=0;
        int j=prefixGCD.size()-1;
        while(i<j){
            ans+=gcd(prefixGCD[i],prefixGCD[j]);
            i++;
            j--;
        }
        return ans;
    }
};