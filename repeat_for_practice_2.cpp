#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int currentend=0;
        int farthest=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,i+nums[i]);

            if(i==currentend){
                jumps++;
                currentend=farthest;
            }
        }
        return jumps;

    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        //sort krlunga pehle array ko fhir ek esa number dhundhunga ki usse aage atleast utne 
        //hi number ho
        sort(citations.begin(),citations.end());
        int n=citations.size();
       
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i){
                return n-i;
            }
        }
        return 0;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector <int> ans(n,1);

        //left product
        int left=1;
        for(int i=0;i<n;i++){
            ans[i]=left;
            left=left*nums[i];
        }
        //right product
        int right=1;
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*right;
            right=right*nums[i];
        }
        return ans;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank=0;
        int currTank=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            int gain=gas[i]-cost[i];

            totalTank+=gain;
            currTank+=gain;
            if(currTank<0){
                start=i+1;
                currTank=0;
            }
        }
        return totalTank>=0? start:-1;
    }
};