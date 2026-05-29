#include <iostream>
#include <queue>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int d){
        val=d;
        left=right=nullptr;
    }
};
class Solution {
public:
    void getleaves(TreeNode*root,queue<int> &q){
        if(!root){
            return;
        }

        if(root->left==nullptr and root->right==nullptr){
            q.push(root->val);
        }
        getleaves(root->left,q);
        getleaves(root->right,q);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> q1,q2;
        getleaves(root1,q1);
        getleaves(root2,q2);
        while(!q1.empty() and !q2.empty()){
            if(q1.front()!=q2.front()){
                return false;
            }
            q1.pop();
            q2.pop();
        }
        return true;
    }
};