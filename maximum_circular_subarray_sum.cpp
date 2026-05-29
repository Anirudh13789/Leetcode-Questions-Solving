#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int linear_kadane = 0;
        int reversed_kadane = 0;
        int total_sum = 0;
        int linear_sum = 0;

        int max_element_val = nums[0];

        // Normal Kadane + max element tracking
        for (int i = 0; i < n; i++) {
            linear_sum += nums[i];
            linear_kadane = max(linear_kadane, linear_sum);
            if (linear_sum < 0)
                linear_sum = 0;

            max_element_val = max(max_element_val, nums[i]);
            total_sum += nums[i];
        }

        // If all elements are negative
        if (linear_kadane == 0)
            return max_element_val;

        // Invert array
        for (int i = 0; i < n; i++) {
            nums[i] = -nums[i];
        }

        // Kadane on inverted array
        int reversed_sum = 0;
        for (int i = 0; i < n; i++) {
            reversed_sum += nums[i];
            reversed_kadane = max(reversed_kadane, reversed_sum);
            if (reversed_sum < 0)
                reversed_sum = 0;
        }

        reversed_kadane = -reversed_kadane;

        int circularsum = total_sum - reversed_kadane;

        return max(circularsum, linear_kadane);
    }
};
