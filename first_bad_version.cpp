#include <iostream>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int solve(int s, int e) {
        if (s > e) return -1;

        int mid = s + (e - s) / 2;

        if (isBadVersion(mid)) {
            int left = solve(s, mid - 1);
            return (left == -1) ? mid : left;
        } else {
            return solve(mid + 1, e);
        }
    }

    int firstBadVersion(int n) {
        return solve(1, n);
    }
};
