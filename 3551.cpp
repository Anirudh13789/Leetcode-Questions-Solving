#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int digitsum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> a;
        for(int x: nums){
            a.push_back({digitsum(x),x});
        }
        sort(a.begin(),a.end());
        unordered_map<int,int> pos;
        for(int i=0;i<n;i++){
            pos[a[i].second]=i;
        }
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i] || pos[nums[i]]==i){
                continue;
            }
            int j=i;
            int cnt=0;
            while(!vis[j]){
                vis[j]=true;
                j=pos[nums[j]];
                cnt++;
            }
            ans+=cnt-1;
        }
        return ans;
    }
};