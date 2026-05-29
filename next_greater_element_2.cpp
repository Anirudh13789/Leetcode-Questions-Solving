#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
    stack<int> s;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        // duplicate the array
        for (int i = 0; i < n; i++) {
            nums.push_back(nums[i]);
        }

        int size = 2 * n;
        vector<int> ng(size);   
        for (int i = 0; i < size; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                ng[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            ng[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int nextgreaterindx = ng[i];
            if (nextgreaterindx != -1) {
                ans.push_back(nums[nextgreaterindx]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;   
    }
};
