#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pair(spells.size(),0);
        
        sort(potions.begin(),potions.end());

        for(int i=0;i<spells.size();i++){
            long long spell=spells[i];

            long long potion_needed=(success+spell-1)/spell;

            auto it=lower_bound(potions.begin(),potions.end(),potion_needed);

            int count=potions.end()-it;
            pair[i]=count;
        }
        return pair;

    }
};