#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int oddcount=0;
        unordered_map<char,int> freq;
        for(char ch:s){
            freq[ch]++;
            if(freq[ch]%2==1){
                oddcount++;
            }
            else{
                oddcount--;
            }
        }
        if(oddcount>1){
            return s.length()-oddcount+1;
        }
        return s.length();
    }
};