#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occurence;

        for(int i=0;i<arr.size();i++){
            occurence[arr[i]]++;
        }
        vector <int> lol;
        for(auto it: occurence){
            lol.push_back(it.second);
        }
        sort(lol.begin(),lol.end());
        for(int i=0;i<lol.size()-1;i++){
            if(lol[i]==lol[i+1]){
                return false;
            }
        }
        return true;
    }
};