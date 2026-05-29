#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(200,0);
        if(ransomNote.length()>magazine.length()){
            return false;
        }
        //freq inc through ransomenote and dec through magazine
        for(int i=0;i<ransomNote.length();i++){
            freq[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++){
            if(freq[magazine[i]]>0){
                freq[magazine[i]]--;
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};