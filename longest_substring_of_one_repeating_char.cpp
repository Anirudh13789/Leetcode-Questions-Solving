#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    struct Node {
        int len;
        int leftChar;
        int rightChar;
        int prefix;
        int suffix;
        int best;
        Node(){
            len=0;
            leftChar=rightChar=-1;
            prefix=suffix=best=0;
        }
    };
    vector<Node> tree;
    string s;

    Node merge(Node a,Node b) {
        if (a.len==0) return b;
        if (b.len==0) return a;

        Node res;
        res.len=a.len+b.len;
        res.leftChar=a.leftChar;
        res.rightChar=b.rightChar;
        res.prefix=a.prefix;
        if (a.prefix==a.len && a.rightChar==b.leftChar) {
            res.prefix=a.len+b.prefix;
        }
        res.suffix=b.suffix;
        if (b.suffix==b.len && a.rightChar==b.leftChar) {
            res.suffix=b.len+a.suffix;
        }

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            tree[node].leftChar = c;
            tree[node].rightChar = c;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * node, l, mid, pos, c);
        } else {
            update(2 * node + 1, mid + 1, r, pos, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            s[index] = c;

            update(1, 0, n - 1, index, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};