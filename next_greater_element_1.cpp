#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Process nums2
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                nextGreater[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Remaining elements have no next greater
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Build answer for nums1
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nextGreater[x]);
        }

        return ans;
    }
};
