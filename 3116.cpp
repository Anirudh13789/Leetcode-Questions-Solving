#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        long long ans = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                // Check whether coin i is selected
                if (mask & (1 << i)) {
                    L = lcm(L, coins[i]);
                    bits++;
                }
            }

            long long curr = x / L;

            if (bits % 2 == 1) {
                ans += curr;
            }
            else {
                ans -= curr;
            }
        }

        return ans;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;
        long long high = 1LL * coins[0] * k;

        while (low < high) {

            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};