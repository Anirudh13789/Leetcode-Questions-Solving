#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        
        // Step 1: XOR all numbers
        for (int x : nums) {
            xr ^= x;
        }
        
        // Step 2: Get rightmost set bit
        int diffBit = xr & (-xr);
        
        int a = 0, b = 0;
        
        // Step 3: Separate numbers into two groups
        for (int x : nums) {
            if (x & diffBit)
                a ^= x;
            else
                b ^= x;
        }
        
        return {a, b};
    }
};
