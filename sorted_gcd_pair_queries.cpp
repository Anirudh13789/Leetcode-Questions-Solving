#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;
        vector<long long> multiple(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                multiple[i] += freq[j];
            }
        }
        vector<long long> exact(mx + 1, 0);
        for (int i = mx; i >= 1; i--) {
            exact[i] = multiple[i] * (multiple[i] - 1) / 2;
            for (int j = 2 * i; j <= mx; j += i) {
                exact[i] -= exact[j];
            }
        }
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }
        vector<int> ans;
        for (long long q : queries) {
            int l = 1, r = mx;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }
        return ans;
    }
};