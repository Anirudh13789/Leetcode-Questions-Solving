#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            switch(ch){
                case '(':
                case '{':
                case '[':
                    s.push(ch);
                    break;
                case ')':
                    if(!s.empty() and s.top()=='('){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case '}':
                    if(!s.empty() and s.top()=='{'){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                    break;
                case ']':
                    if(!s.empty() and s.top()=='['){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                    break;
            }
        }
        return s.empty();

    }
};