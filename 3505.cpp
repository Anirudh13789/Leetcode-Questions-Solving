#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long operations(vector<int> a){
        sort(a.begin(),a.end());
        int mid=a.size()/2;
        int ans=0;
        for(int i=0;i<a.size();i++){
            ans+=abs(a[i]-a[mid]);
        }
        return ans;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
       int n=nums.size();
       vector<long long> oper;
       for(int i=0;i<=n-x;i++){
            vector<int> a;
            for(int j=i;j<i+x;j++){
                a.push_back(nums[j]);
            }
            oper.push_back(operations(a));
       }
       int m=oper.size();
        vector<vector<long long>>dp(m+x+1,vector<long long>(k + 1,LLONG_MAX/2));

        for(int i=0;i<=m+x;i++) {
            dp[i][0]=0;
        }
        for(int i=m-1;i>=0;i--) {
            for (int j=1;j<=k;j++) {
                dp[i][j]=dp[i+1][j];
                dp[i][j]=min(dp[i][j],oper[i]+dp[i+x][j-1]);
            }
        }
        if(dp[0][k]==LLONG_MAX/2) {
            return -1;
        }
        return dp[0][k];
    }
};