#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int boom : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && boom < 0) {
                if (abs(st.top()) < abs(boom)) {
                    st.pop();          // top explodes, keep checking
                }
                else if (abs(st.top()) == abs(boom)) {
                    st.pop();          // both explode
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;  // current explodes
                    break;
                }
            }

            if (!destroyed) {
                st.push(boom);
            }
        }

        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
