#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size());
        int maxcandies = INT_MIN;

        for (int i = 0; i < candies.size(); i++) {
            maxcandies = max(maxcandies, candies[i]);
        }

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxcandies) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};
