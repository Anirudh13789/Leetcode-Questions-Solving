#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp="";

        for(int i=0;i<=path.size();i++){
            if(i==path.size() || path[i]=='/'){
                if(temp=="" || temp=="."){

                }
                else if(temp==".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                }
                else{
                    st.push_back(temp);
                }
                temp="";
            }
            else{
                temp+=path[i];
            }
        }
        if(st.empty()){
            return "/";
        }
        string ans="";
        for(int i=0;i<st.size();i++){
            ans+="/";
            ans+=st[i];
        }
        return ans;
    }
};