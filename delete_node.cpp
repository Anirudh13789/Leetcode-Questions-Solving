#include <iostream>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if(key<root->val){
                root->left=deleteNode(root->left,key);
            }
            else if(key>root->val){
                root->right=deleteNode(root->right,key);
            }
            else{
                if(!root->left && !root->right){
                    return NULL;
                }
                if(!root->left || !root->right){
                    return root->left?root->left:root->right;
                }
                TreeNode*temp=root->left;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
            }
        }
        return root;
    }
};