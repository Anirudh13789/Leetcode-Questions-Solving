#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        vector<int> ans(2);

        for(int i = 0; i < n; i++) {
            count[nums[i]]++;
        }

        for(int i = 1; i <= n; i++) {
            if(count[i] == 2) ans[0] = i;   // duplicate
            if(count[i] == 0) ans[1] = i;   // missing
        }

        return ans;
    }
};
