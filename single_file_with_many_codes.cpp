#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
class ListNode{
public:
    ListNode*next;
    int val;
    ListNode(int d){
        val=d;
        next=NULL;
    }
};
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
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int t) {
        int count=0;
        int n=flowerbed.size();
        for(int i=0;i<n;i++){
            if(flowerbed[i]==0){
                bool emptyLeft=(i==0) || (flowerbed[i-1]==0);
                bool emptyRight=(i==n-1)|| (flowerbed[i+1]==0);

                if(emptyLeft && emptyRight){
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        return count>=t;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int chunks=0,mx=0;
        for(int i=0;i<n;i++){
            mx=max(arr[i],mx);
            if(mx==i){
                chunks++;
            }
        }
        return chunks;
    }
};
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1e9){
                int start=nums[i],count=0;
                while(nums[start]!=1e9){
                    int temp=start;
                    start=nums[start];
                    count++;
                    nums[temp]=1e9;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int max_val=0;
        int minIncrements=0;

        for(int val:nums){
            max_val=max(max_val,val);
        }
        vector<int> frequencyCount(n+max_val,0);

        for(int val:nums){
            frequencyCount[val]++;
        }
        for(int i=0;i<frequencyCount.size();i++){
            if(frequencyCount[i]<=1){
                continue;
            }
            int duplicates=frequencyCount[i]-1;
            frequencyCount[i+1]+=duplicates;
            frequencyCount[i]=1;
            minIncrements+=duplicates;
        }
        return minIncrements;

    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1-k];
    }
};
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int leftMaxSoFar=nums[0];
        int maxSoFar=nums[0];
        for(int i=1;i<n;i++){
            maxSoFar=max(maxSoFar,nums[i]);
            if(nums[i]<leftMaxSoFar){
                ans=i+1;
                leftMaxSoFar=maxSoFar;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size(),m=mat[0].size();
        if(n*m != r*c){
            return mat;
        }

        vector<vector<int>>ans (r,vector<int>(c));

        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[x][y]=mat[i][j];
                y++;
                if(y==c){
                    y=0;
                    x++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;
        
        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);
            
            for (int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }
            
            result.push_back(currentRow);
            prevRow = currentRow;
        }
        
        return result;
    }
};
class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        int ans=0;
        for(int i=0;i<costs.size();i++){
            ans+=climbStairs(n-costs[i],costs);
        }
        return ans;
    }
};
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int ps[100]={0};

        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            ps[i]%=n;
        }
        int remaindersCount[100]={1};
        for(int i=0;i<n;i++){
            remaindersCount[ps[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(remaindersCount[i]+(remaindersCount[i]-1)/2);
        }
        return ans;
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    cost[i][j]=grid[i][j];
                }
                else{
                    int up=(i>0)? cost[i-1][j]:INT_MAX;
                    int left=(j>0)? cost[i][j-1]:INT_MAX;

                    cost[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return cost[m-1][n-1];
    }
};
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket;
        int left=0,maxPicked=0;

        for(int right=0;right<fruits.size();right++){
            basket[fruits[right]]++;

            while(basket.size()>2){
                basket[fruits[left]]--;
                if(basket[fruits[left]]==0){
                    basket.erase(fruits[left]);
                   
                }
                left++;
            }
            maxPicked=max(maxPicked,right-left+1);
        }
        return maxPicked;
    }

};
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int mi=INT_MAX, mx=INT_MIN;
        bool flag= false;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                flag=true;
            }
            if(flag){
                mi=min(mi,nums[i]);
            }
        }
        flag=false;

        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                flag=true;
            }
            if(flag){
                mx=max(mx,nums[i]);
            }
        }

        int l,r;
        for(l=0;l<n;l++){
            if(nums[l]>mi){
                break;
            }
        }
        for(r=n-1;r>=0;r--){
            if(nums[r]<mx){
                break;
            }
        }
        return r-l<0 ? 0 : r-l+1;
    }
};
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum_a=0,sum_b=0;
        for(int i=0;i<aliceSizes.size();i++){
            sum_a+=aliceSizes[i];
        }
        for(int j=0;j<bobSizes.size();j++){
            sum_b+=bobSizes[j];
        }
        int d=(sum_a-sum_b)/2;

        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());

        int i=0,j=0;
        while(i<aliceSizes.size() && j<bobSizes.size()){
            int diff=aliceSizes[i]-bobSizes[j];
            if(d==diff){
                return{aliceSizes[i],bobSizes[j]};
            }
            if(diff<d){
                i++;
            }
            else{
                j++;
            }
        }
        return {-1,-1};
        
    }
};
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> num(100);
        int ret=0;
        for(auto & it: dominoes){
            int val=it[0]<it[1]?it[0]*10+it[1]:it[1]*10+it[0];
            ret+=num[val];
            num[val]++;
        }
        return ret;
    }
};
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]>0 && nums[i]<=n and nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];

        int deltaY=y2-y1;
        int deltaX=x2-x1;

        for(int i=2;i<coordinates.size();i++){
            int x3=coordinates[i][0];
            int y3=coordinates[i][1];

            if(deltaY*(x3-x2)!=deltaX*(y3-y2)){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n=timeSeries.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            ans+=min(timeSeries[i+1]-timeSeries[i],duration);
        }
        return ans+duration;
    }
};
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue <int> q;
        int n=deck.size();

        for(int i=0;i<n;i++){
            q.push(i);
        }
        sort(deck.begin(),deck.end());

        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[q.front()]=deck[i];
            q.pop();

            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        
        string curr = "";
        int num = 0;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                countStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (ch == ']') {
                int times = countStack.top();
                countStack.pop();
                
                string prev = stringStack.top();
                stringStack.pop();
                
                while (times--) {
                    prev += curr;
                }
                curr = prev;
            }
            else {
                curr += ch;
            }
        }
        
        return curr;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit:num){
            while(!st.empty() && k>0 && st.top()>digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());

        int i=0;
        while(i<result.size() && result[i]=='0'){
            i++;
        }
        result=result.substr(i);

        if(result.empty()){
            return 0;
        }
        return result;
    }
};
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <int> st;
        int C=INT_MIN;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]<C){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                C=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0,bal=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                bal++;
            }
            else{
                bal--;
                if(s[i-1]=='('){
                    ans+=1 << bal;
                }
            }
        }
        return ans;
    }
};
class Pair{
public:
    int value;
    int span;
};
class StockSpanner {
public:
    stack<Pair> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cspan=1;
        while(!s.empty() and s.top().value<=price){
            cspan+=s.top().span;
            s.pop();
        }
        s.push({price,cspan});
        return cspan;
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       int n=pushed.size();
       stack<int> st;
       
       int j=0;
       for(int x:pushed){
            st.push(x);

            while(!st.empty() && j<n && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        return j==n;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int x) {
        int f= ++freq[x];
        maxFreq=max(f,maxFreq);

        group[f].push(x);
    }
    
    int pop() {
        int x=group[maxFreq].top();
        group[maxFreq].pop();

        freq[x]--;

        if(group[maxFreq].empty()){
            maxFreq--;
        }
        return x;
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string operators="+-*/";
        for(string token:tokens){
            if(operators.find(token)==string::npos){
                st.push(stoi(token));
                continue;
            }
            int number2=st.top();
            st.pop();
            int number1=st.top();
            st.pop();
            int result=0;
            if(token=="+"){
                result=number1+number2;
            }
            else if(token == "-"){
                result=number1-number2;
            }
            else if(token == "*"){
                result=number1*number2;
            }
            else{
                result=number1/number2;
            }
            st.push(result);
        }
        return st.top();
    }
};
class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        int factors[3]={2,3,5};
        for(int i=0;i<3;i++){
            n=keepDividingWhenDivisible(n,factors[i]);
        }
        return n==1;
    }
    int keepDividingWhenDivisible(int dividend,int divisor){
        while(dividend%divisor==0){
            dividend/=divisor;
        }
        return dividend;
    }
};
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int total=1<<n;
        for(int i=0;i<total;i++){
            result.push_back(i^(i>>1));
        }
        return result;
    }
};
class Solution {
public:
    int nthUglyNumber(int n) {
        set <long> s;
        s.insert(1);
        long current=1;
        for(int i=0;i<n;i++){
            current= *s.begin();
            s.erase(s.begin());

            s.insert(current*2);
            s.insert(current*3);
            s.insert(current*5);
        }
        return current;
    }
};
class Solution {
public:
    int numTrees(int n) {
       long long result=1;
       for(int i=0;i<n;i++){
            result=result*2*(2*i+1)/(i+2);
       } 
       return (int) result;
    }
};
class Solution {
public:
    int numSquares(int n) {
        int sqrtN=sqrt(n);
        if(sqrtN*sqrtN==n){
            return 1;
        }
        for(int i=1;i*i<=n;i++){
            int square=i*i;
            int base=sqrt(n-square);

            if(base*base==n-square){
                return 2;
            }
        }
        while(n%4==0){
            n=n/4;
        }
        if(n%8!=7){
            return 3;
        }
        return 4;
    }
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oh=NULL,*ot=NULL,*eh=NULL,*et=NULL;
        int i=0;
        while(head){
            ListNode* curr=head;
            head=head->next;
            curr->next=NULL;

            if(i%2==0){
                if(!eh){
                    eh=et=curr;
                }
                else{
                    et->next=curr;
                    et=curr;
                }
            }
            else{
                if(!oh){
                    oh=ot=curr;
                }
                else{
                    ot->next=curr;
                    ot=curr;
                }
            }
            i++;
        }
        if(et){
            et->next=oh;
        }
        return eh;
    }
};
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode*l = NULL;
        int c=0;

        while(l1 != NULL || l2 != NULL || c != 0){
            int d1=l1!=NULL ? l1->val :0;
            int d2=l2!=NULL ? l2->val :0;
            int s=d1+d2+c;
            ListNode*n = new ListNode(s%10);
            n->next=l;
            l=n;
            c=s/10;
            l1=l1!=NULL ? l1->next :l1;
            l2=l2!=NULL ? l2->next :l2;
        }
        return l;
    }
};
class Solution {
public:
    int lengthL(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

    void reverseLL(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;

        ListNode* headDummy = new ListNode(-1);
        headDummy->next = head;

        ListNode* prev = headDummy;
        int remaining_len = lengthL(head);

        while (remaining_len >= k) {
            ListNode* tail = head;
            for (int i = 1; i < k; i++) {
                tail = tail->next;
            }

            ListNode* nextGroup = tail->next;
            tail->next = NULL;

            reverseLL(head);

            prev->next = tail;
            head->next = nextGroup;

            prev = head;
            head = nextGroup;

            remaining_len -= k;
        }

        return headDummy->next;
    }
};

