#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        map<char,int> mp;

        int maxi=0;
        int ans=-1;

        while(j<n){
            mp[s[j]]++;
            maxi=max(maxi,mp[s[j]]);

            if((j-i+1)-maxi>k){
                mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};