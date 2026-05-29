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
    int dfs(TreeNode*root,int maxsofar){
        if(!root){
            return 0;
        }
        int count=0;
        if(root->val>=maxsofar){
            count=1;
            maxsofar=root->val;
        }
        count+=dfs(root->left,maxsofar);
        count+=dfs(root->right,maxsofar);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};