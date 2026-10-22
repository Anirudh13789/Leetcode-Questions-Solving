#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        int ans = 1000000000;

        for (int step = -1; step <= 1; step += 2) {
            bool ok = true;

            for (int i = 1; i < n; i++) {
                int prev = (zero + (i - 1) * step + n) % n;
                int curr = (zero + i * step + n) % n;

                if (nums[curr] != i) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (step == 1) {
                    ans = min(ans, min(zero, n - zero + 2));
                } else {
                    ans = min(ans, min(zero + 2, n - zero));
                }
            }
        }

        return ans == 1000000000 ? -1 : ans;
    }
};