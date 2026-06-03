#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
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

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            if(!isalnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;

    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<=s.length()-1 && j<=t.length()-1){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        return i==s.length();

    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            int total=numbers[left]+numbers[right];
            if(total==target){
                return{left+1,right+1};
            }
            else if(total<target){
                left++;
            }
            else{
                right--;
            }
        }
        return{};
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxwater=0;
        while(left<right){
            int width=right-left;
            int height=min(heights[right],heights[left]);
            int currentwater=width*height;

            maxwater=max(maxwater,currentwater);

            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0;
        int minLen=INT_MAX;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                minLen=min(minLen,right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        return (minLen==INT_MAX) ? 0:minLen;
    }
};