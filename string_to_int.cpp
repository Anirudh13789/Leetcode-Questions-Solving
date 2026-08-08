#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long ans=0;
        while(i<n && s[i]>='0' && s[i]<='9'){
            ans=ans*10+(s[i]-'0');
            if(sign==1 && ans>INT_MAX){
                return INT_MAX;
            }
            if(sign==-1 && -ans<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return (int)(sign*ans);
    }
};