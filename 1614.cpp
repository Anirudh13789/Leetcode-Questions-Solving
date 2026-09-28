#include <iostream>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int sol=0,curr=0;
        for(auto i:s){
            if(i=='('){
                curr++;
                sol=max(curr,sol);
            }
            else if(i==')'){
                curr--;
            }
        }
        return sol;
    }
};