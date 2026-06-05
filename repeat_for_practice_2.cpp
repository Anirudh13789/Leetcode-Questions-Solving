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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256,-1);
        int left=0, ans=0;
        for(int right=0;right<s.length();right++){
            left=max(left,arr[s[right]]+1);
            arr[s[right]]=right;
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c=0;
        int z=0;
        int t=nums.size()-1;
        while(c<=t){
            if(nums[c]==0){
                swap(nums[c],nums[z]);
                c++;
                z++;
            }
            else if(nums[c]==1){
                c++;
            }
            else{
                swap(nums[c],nums[t]);
                t--; 
            }
        }
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int product=1;
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size()){
            product*=nums[j];
            while(product>=k){
                product=product/nums[i];
                i++;
            }
            ans=ans+j-i+1;   
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i=1;i<nums.size();i=i+2){
            if(nums[i-1]>nums[i]){
                swap(nums[i-1],nums[i]);
            }
            if(i+1<nums.size() && nums[i]<nums[i+1]){
                swap(nums[i],nums[i+1]);
            }
        }
    }
};