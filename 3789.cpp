#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long totalcost=0;
        if(cost1+cost2<=costBoth){
            totalcost=1LL*cost1*need1+1LL*cost2*need2;
        }
        else{
            int cnt3=min(need1,need2);
            totalcost=1LL*cnt3*costBoth;
            need1-=cnt3;
            need2-=cnt3;
            if(need1>0){
                totalcost+=1LL*need1*min(cost1,costBoth);
            }
            else if(need2>0){
                totalcost+=1LL*need2*min(cost2,costBoth);
            }
        }
        return totalcost;
    }
};