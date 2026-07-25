#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;
        while(n>0){
            num.push_back(n%10);
            n=n/10;
        }
        sort(num.begin(),num.end());
        int ans=num[num.size()-1]*num[num.size()-2];
        return ans;
    }
};