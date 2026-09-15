#include <iostream>
using namespace std;
class Solution {
public:
    bool ispal(int l,int r,string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int maxPalindromes(string& s, int k) {
        int n=s.length();
        int cnt=0;
        int idx=0;
        for(int r=k-1;r<n;r++){
            int l=r-k+1;
            bool add=false;
            if(l>=idx && ispal(l,r,s)){
                add=true;
            }
            else if(l>idx && ispal(l-1,r,s)){
                add=true;
            }
            if(add){
                cnt++;
                idx=r+1;
            }
        }
        return cnt;
    }
};