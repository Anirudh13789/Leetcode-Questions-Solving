#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        priority_queue<int> pq;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            pq.push(abs(nums1[i]-nums2[i]));
        }
        long long k= k1+k2;
        while(k>0 && pq.top()>0){
            int x=pq.top();
            pq.pop();
            pq.push(x-1);
            k--;
        }
        long long ans=0;
        while(!pq.empty()){
            long long x=pq.top();
            ans+=x*x;
            pq.pop();
        }
        return ans;
    }   
};