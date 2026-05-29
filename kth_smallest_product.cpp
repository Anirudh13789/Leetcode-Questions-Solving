#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long lo = -1e10, hi = 1e10;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countPairs(nums1, nums2, mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }

    long long countPairs(vector<int>& a, vector<int>& b, long long x) {
        long long cnt = 0;
        int m = b.size();

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 0) {
                if (x >= 0) cnt += m;
            }
            else if (a[i] > 0) {
                cnt += upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
            }
            else {
                cnt += b.end() - lower_bound(b.begin(), b.end(), (long double)x / a[i]);
            }
        }
        return cnt;
    }
};
