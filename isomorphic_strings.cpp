#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> indexs(200,0);
        vector<int> indext(200,0);

        for(int i=0;i<s.length();i++){
            if(indexs[s[i]]!=indext[s[i]]){
                return false;
            }
            indexs[s[i]]=i+1;
            indext[t[i]]=i+1;
        }
        return true;
    }
};