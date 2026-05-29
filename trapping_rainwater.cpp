#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    
    int leftheight(vector<int> &height,int i){
        int max=INT_MIN;
        for(int j=0;j<i;j++){
            if(height[j]>max){
                max=height[j];
            }
        }   
        return max;
    }
    int rightheight(vector<int> &height,int i){
        int max=INT_MIN;
        for(int j=i+1;j<height.size();j++){
            if(height[j]>max){
                max=height[j];
            }
        }
        return max;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ans(n,0);
        for(int i=0;i<height.size();i++){
            int value=min(leftheight(height,i),rightheight(height,i))-height[i];
            ans[i]=max(0,value);
        }
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=ans[i];
        }
        return sum;
    }
};