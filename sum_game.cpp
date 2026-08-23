#include <iostream>
using namespace std;
class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftsum=0;
        int rightsum=0;
        int leftq=0;
        int rightq=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?'){
                leftq++;
            }
            else{
                leftsum+=num[i]-'0';
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?'){
                rightq++;
            }
            else{
                rightsum+=num[i]-'0';
            }
        }
        if((leftq+rightq)%2!=0){
            return true;
        }
        int sumdiff=leftsum-rightsum;
        int qdiff=leftq-rightq;
        if(sumdiff*2==-9*qdiff){
            return false;
        }
        return true;
    }
};