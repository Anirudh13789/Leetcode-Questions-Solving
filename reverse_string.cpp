#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(j>i){
            swap(s[i],s[j]);
            j=j-1;
            i=i+1;
        }
    }
};