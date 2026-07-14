#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int write=0;
        int read=0;
        while(read<n){
            char current=chars[read];
            int count=0;

            while(read<n && chars[read]==current){
                read++;
                count++;
            }
            chars[write++]=current;
            if(count>1){
                string count_str=to_string(count);
                for(char digit : count_str){
                    chars[write++]=digit;
                }
            }
        }
        return write;

    }
};