#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& a, int key) {
        int s=0;
        int n=a.size();
        int e=n-1;

        while(s<=e){
            int mid=(s+e)/2;

            if(a[mid]==key){
                return mid;
            }

            else if(a[mid]<=a[n-1]){
                if(key>=a[mid] && key<=a[n-1]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

            else{

                if(key>=a[0] && key<=a[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
        }
        return -1;
    }
};