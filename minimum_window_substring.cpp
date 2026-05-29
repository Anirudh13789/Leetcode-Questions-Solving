#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int freqt[256] = {0};
        int freqs[256] = {0};

        // store frequency of characters in t
        for (char c : t) {
            freqt[c]++;
        }

        int required = t.size();
        int start = 0, minLen = INT_MAX, left = 0;

        for (int right = 0; right < s.size(); right++) {
            freqs[s[right]]++;

            if (freqt[s[right]] > 0 && freqs[s[right]] <= freqt[s[right]]) {
                required--;
            }

            // when all characters matched
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                freqs[s[left]]--;
                if (freqt[s[left]] > 0 && freqs[s[left]] < freqt[s[left]]) {
                    required++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
