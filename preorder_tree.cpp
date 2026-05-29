/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;
class TreeNode{
public:
    TreeNode*left;
    TreeNode*right;
    int val;
    TreeNode(int v){
        val=v;
        left=right=NULL;
    }
};
 class Solution {
public:
    void helper(TreeNode*root,vector<int> &ans){
        if(root==NULL){
            return ;
        }

        ans.push_back(root->val);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};