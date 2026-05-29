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
    bool ismirror(TreeNode*t1,TreeNode*t2){
        if(t1==NULL && t2==NULL){
            return true;
        }
        if(t1==NULL || t2==NULL){
            return false;
        }
        if(t1->val!=t2->val){
            return false;
        }
        return ismirror(t1->left,t2->right) && ismirror(t1->right,t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return ismirror(root->left,root->right);
    }
};