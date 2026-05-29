#include <iostream>
#include <vector>
using namespace std;
int solve(vector <int> &num){
    for(int i=1;i<num.size();i++){
        num[i]=num[i]+num[i-1];
    }
    for(int i=1;i<num.size()-1;i++){
        if(num[i-1]==num[num.size()-1]-num[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    vector <int> num;
}