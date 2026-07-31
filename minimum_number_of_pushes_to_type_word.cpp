#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        for(char ch:word){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end());
        int minpushing=0;
        for(int i=25,pushcnt=0;i>=0;i--){
            int currEleIdx=25-i;
            if(currEleIdx%8==0){
                pushcnt++;
            }
            minpushing+=freq[i]*pushcnt;
        }
        return minpushing;
    }
};