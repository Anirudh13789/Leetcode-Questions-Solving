#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class ListNode{
public:
    ListNode*next;
    int val;
    ListNode(int d){
        val=d;
        next=NULL;
    }
};
// code-1
class Solution {
public:
    int fib(int n) {
        if(n==1 or n==0){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};
//code-2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;

        while(start<=end){
            int mid=(start+end)/2;

            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                start=mid+1;
            }
            if(nums[mid]>target){
                end=mid-1;
            }
        }
        return -1;
    }
};
//code-3
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        while(n%2==0){
            n=n/2;
        }
        return n==1;
    }
};

//code-4
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){
            return false;
        }
        while(n%3==0){
            n=n/3;
        }
        return n==1;
    }
};

//code-5
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        while(n%4==0){
            n=n/4;
        }
        return n==1;
    }
};

//code-6
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());

        int left=0, right=arr.size()-1;
        while(left<right){
            int sum=arr[left].first+arr[right].first;

            if(sum==target){
                return{arr[left].second,arr[right].second};
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        return{};
    }  
};

//code-7
class Solution {
public:
    bool isPalindrome(int x) {
        //number less than zero or ending with zero
        if(x<0 or (x%10==0 and x>=10)){
            return false;
        }
        long int originalnumber=x;
        long int reversednumber=0;

        while(x>0){
            reversednumber=reversednumber*10+x%10;
            x=x/10;
        }
        if(reversednumber==originalnumber){
            return true;
        }
        else{
            return false;
        }
    }
};
//code-8
class Solution {
public:
    int romanToInt(string s) {
        int value=0;

        for(int i=0;i<s.size();i++){
            int curr;
            if(s[i]=='I'){
                curr=1;
            }
            else if(s[i]=='V'){
                curr=5;
            }
            else if(s[i]=='X'){
                curr=10;
            }
            else if(s[i]=='L'){
                curr=50;
            }
            else if(s[i]=='C'){
                curr=100;
            }
            else if(s[i]=='D'){
                curr=500;
            }
            else if(s[i]=='M'){
                curr=1000;
            }

            if(i+1<s.size()){
                int next;
                if(s[i+1]=='I'){
                    next=1;
                }
                else if(s[i+1]=='V'){
                    next=5;
                }
                else if(s[i+1]=='X'){
                    next=10;
                }
                else if(s[i+1]=='L'){
                    next=50;
                }
                else if(s[i+1]=='C'){
                    next=100;
                }
                else if(s[i+1]=='D'){
                    next=500;
                }
                else if(s[i+1]=='M'){
                    next=1000;
                }
                if(curr<next){
                    value=value-curr;
                } 
                if(curr>=next){
                    value=value+curr;
                }                 
            }
            else{
                value=value+curr;
            }
        }
        return value;
    }
};

//code-9
class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(ch=='(' or ch=='[' or ch=='{'){
                s.push(ch);
                
            }
            else if(ch==')'){
                if(!s.empty() and s.top()=='('){
                    s.pop();    
                }
                else{
                    return false;
                }
                
            }
            else if(ch==']'){
                if(!s.empty() and s.top()=='['){
                    s.pop();    
                }
                else{
                    return false;
                }
                
            }
            else if(ch=='}'){
                if(!s.empty() and s.top()=='{'){
                    s.pop();    
                }
                else{
                    return false;
                }
                
            }
        }
        return s.empty();
    }
};
//code-10
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        if(list1->val <= list2->val){
            ListNode*nh=list1;
            nh->next=mergeTwoLists(list1->next,list2);
            return nh;
        }
        if(list1->val >= list2->val){
            ListNode*nh=list2;
            nh->next=mergeTwoLists(list1,list2->next);
            return nh;
        }
        return {};
    }
};
//code-11
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return start;
    }
};
//code-12
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int count=0;

        //if string contains space at last
        while(i>=0 and s[i]==' '){
            i--;
        }
        while(i>=0 and s[i]!=' '){
            count++;
            i--;
        }
        return count;
    }
};

//code-13
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

//code-14
class Solution {
public:
    int mySqrt(int x) {
        long long r=x;
        while(r*r>x){
            r=(r+x/r)/2;
        }
        return r;   
    }
};

//code-15
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        return nums;
    }
};

//code-16
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

//code-17
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[nums[i]];
        }
        return ans;
    }
};

//code-18
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return true;
            }
        }
        return false;
    }
};

//code-19
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expectedSum=(n*(n+1))/2;
        int actualsum=0;
        for(int i=0;i<n;i++){
            actualsum+=nums[i];
        }
        return expectedSum-actualsum;
    }
};

//code-20
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

//code-21
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofit=0;
        for(int i=1;i<prices.size();i++){
            minprice=min(minprice,prices[i]);
            maxprofit=max(maxprofit,prices[i]-minprice);
        }
        return maxprofit;
    }
};

//code-22
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int count=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]==nums[i]){
                    count++;
                }
            }
            if(count>n/2){
                return nums[i];
            }
        }
        return{};
    }
};

//code-23
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};