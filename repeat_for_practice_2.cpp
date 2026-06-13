#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <map>
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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<m && j>=0 ){
            if(matrix[i][j]==target){
                return true;
            }
            if(target>matrix[i][j]){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(i>=0 and j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expectedsum=n*(n+1)/2;
        int actualsum=0;
        for(int i=0;i<n;i++){
            actualsum+=nums[i];
        }
        return expectedsum-actualsum;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=nums[0];
        int vote=1;
        for(int i=1;i<n;i++){
            if(vote==0){
                candidate=nums[i];
                vote=1;
            }
            else if(candidate==nums[i]){
                vote++;
            }
            else{
                vote--;
            }
        }
        return candidate;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int seat1=0,seat2=0;
        int vote1=0,vote2=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x==seat1){
                vote1++;
            }
            else if(x==seat2){
                vote2++;
            }
            else if(vote1==0){
                seat1=x;
                vote1=1;
            }
            else if(vote2==0){
                seat2=x;
                vote2=1;
            }
            else{
                vote1--;
                vote2--;
            }
        }
        vote1=0;
        vote2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==seat1){
                vote1++;
            }
            else if(nums[i]==seat2){
                vote2++;
            }
        }
        vector<int> result;
        if(vote1>n/3){
            result.push_back(seat1);
        }
        if(vote2>n/3){
            result.push_back(seat2);
        }
        return result;
        
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum=totalsum+nums[i];
        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){     
            
            if(leftsum==totalsum-leftsum-nums[i]){
                return i;
            }
            leftsum=leftsum+nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-1;j++){
                int sum=nums[i]+nums[j];

                int k=lower_bound(nums.begin()+j+1,nums.end(),sum)-nums.begin();
                count+=k-j-1;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            int nE=nums[i];
            sum=max(sum+nE,nE);
            mx=max(mx,sum);
        }
        return mx;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1;
        if (r > N - r) {
            r = N - r;
        }
        
        long long result = 1; 
        for (int i = 1; i <= r; ++i) {
            result *= (N - r + i);
            result /= i;
        }
        
        return result; 
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pi=0;
        int ni=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pi]=nums[i];
                pi=pi+2;
            }
            else{
                ans[ni]=nums[i];
                ni=ni+2;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target){
                return m;
            }
            else{
                if(nums[m]>=nums[0]){
                    if(target>=nums[s] and target<nums[m]){
                        e=m-1;
                    }
                    else{
                        s=m+1;
                    }
                }
                else{
                    if(target>nums[m] and target<=nums[e]){
                        s=m+1;
                    }
                    else{
                        e=m-1;
                    }
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();

        int i = n - 2;
        while (i >= 0 && arr[i] <= arr[i + 1]) {
            i--;
        }

        if (i < 0) return arr;

        int j = n - 1;

        while (arr[j] >= arr[i]) {
            j--;
        }

        while (j > 0 && arr[j] == arr[j - 1]) {
            j--;
        }

        swap(arr[i], arr[j]);

        return arr;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) { 
        if(n<0){
            return false;
        }
        while(n%2==0){
            n=n/2;
        }
        return n==1;
    }
};
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0;
        int currMin=0;
        int maxSum=nums[0];
        int minSum=nums[0];
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            currMax=max(currMax,0)+nums[i];
            maxSum=max(maxSum,currMax);
            currMin=min(currMin,0)+nums[i];
            minSum=min(minSum,currMin);
            totalSum+=nums[i];
        }

        if(totalSum==minSum){
            return maxSum;
        }
        return max(maxSum,totalSum-minSum);
    }
};
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int num:nums){
            xorr=xorr^num;
        }
        long long setbit=(long long)xorr & (-(long long)xorr);
        int x=0,y=0;
        for(int num:nums){
            if(num & setbit){
                x=x^num;
            }
            else{
                y=y^num;
            }
        }
        return {x,y};
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int bit=0;bit<32;bit++){
            int count=0;
            for(int num:nums){
                if(num & (1<<bit)){
                    count++;
                }
            }
            if(count%3!=0){
                result |= (1 << bit);
            }
        }
        return result;
    }
};
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int nl=s.length();
        int ml=t.length();
        if(nl!=ml){
            return false;
        }
        map<char,char> m;
        map<char,char> n;
        for(int i=0;i<nl;i++){
            if(m.find(s[i])!=m.end()){
                if(m[s[i]]!=t[i]){
                    return false;
                }
                continue;
            }
            else if(n.find(t[i])!=n.end()){
                return false;
            }
            m[s[i]]=t[i];
            n[t[i]]=s[i];
        }
        return true;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();

        //transpose
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse rows
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<k){
                swap(matrix[i][j],matrix[i][k]);
                j++;
                k--;
            }
        }
    }
};
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        while(i<s.length() and j<t.length()){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-3;i>=0;--i){
            if(nums[i]+nums[i+1]>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        int left_max=0,right_max=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]>=left_max){
                    left_max=height[left];
                }
                else{
                    ans+=left_max-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=right_max){
                    right_max=height[right];
                }
                else{
                    ans+=right_max-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int area=0;
        while(left<right){
            int width=right-left;
            int height=min(heights[left],heights[right]);
            int currentArea=height*width;
            area=max(currentArea,area);
            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMax= INT_MIN;
        long long secondMax= INT_MIN;
        long long thirdMax= INT_MIN;

        for(int num:nums){
            if(num==firstMax || num==secondMax || num==thirdMax){
                continue;
            }
            if(num>firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=num;
            }
            else if(num>secondMax){
                thirdMax=secondMax;
                secondMax=num;
            }
            else if(num>thirdMax){
                thirdMax=num;
            }
        }
        return thirdMax;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> h;
        h[0]=-1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]==1)?1:-1;
            if(h.find(sum)!=h.end()){
                ans=max(ans,i-h[sum]);
            }
            else{
                h[sum]=i;
            }
        }
        return ans;
    }
};
