#include <iostream>
#include <stack>
using namespace std;
class MinStack {
    stack <int> st;
    stack <int> minstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty() || val<minstack.top()){
            minstack.push(val);
        }
        else{
            minstack.push(minstack.top());
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minstack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */