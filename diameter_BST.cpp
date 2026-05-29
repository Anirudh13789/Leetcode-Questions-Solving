#include <iostream>
#include <queue>
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
class Solution {
public:
    int heightLL(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int lsth=heightLL(root->left);
        int rsth=heightLL(root->right);
        return max(rsth,lsth)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int op1=diameterOfBinaryTree(root->right);
        int op2=diameterOfBinaryTree(root->left);
        int op3=heightLL(root->right)+heightLL(root->left);
        return max(op1,max(op2,op3));
    }
};