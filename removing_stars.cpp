#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        char ch;
        for(int i=0;i<s.length();i++){
            ch=s[i];
            if(ch=='*'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};