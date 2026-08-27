#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        prices.push_back(x);
    }
    sort(prices.begin(),prices.end());
    int q;
    cin>>q;
    while(q--){
        int money;
        cin>>money;
        int cnt=upper_bound(prices.begin(),prices.end(),money)-prices.begin();
        cout<<cnt<<endl;
    }
    return 0;
}