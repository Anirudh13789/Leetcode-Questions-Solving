#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<temp.length();j++){
                    st.push(temp[j]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};