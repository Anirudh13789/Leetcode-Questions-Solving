#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        for (int x : nums) {
            if (x >= 0) pos.push_back(x);
        }      
        int m = pos.size();
        if (m == 0) return nums;      
        k = k % m;
        rotate(pos.begin(), pos.end() - k, pos.end());
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                nums[i] = pos[idx++];
            }
        }
        return nums;
    }
};
