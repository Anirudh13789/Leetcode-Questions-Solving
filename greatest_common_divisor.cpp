#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[nums.size()-1]);
    }
};
