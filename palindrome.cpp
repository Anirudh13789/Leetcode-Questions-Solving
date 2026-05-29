#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        //negative numbers and number ending with 0 will always give false
        if(x<0 or (x%10==0 and x!=0)){
            return false;
        }
        int reversed=0;
        while(x>0){
            reversed=reversed*10 + x%10;
            x=x/10;
        }
        if(reversed=x){
            return true;
        }
        return{};

    }
};