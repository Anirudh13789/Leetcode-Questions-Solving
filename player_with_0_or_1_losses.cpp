#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost_map;

        for(int i=0;i<matches.size();i++){
            int loser = matches[i][1];
            lost_map[loser]++;
        }

        vector <int> never_lost;
        vector <int> lost_once;

        for(int i=0;i<matches.size();i++){
            int winner= matches[i][0];
            int losed= matches[i][1];
            if(lost_map.find(winner)==lost_map.end()){
                never_lost.push_back(winner);
                lost_map[winner]=2;
            }
            if(lost_map[losed]==1){
                lost_once.push_back(losed);
            }

        }
        sort(begin(never_lost),end(never_lost));
        sort(begin(lost_once),end(lost_once));
        return {never_lost,lost_once};
    }
};