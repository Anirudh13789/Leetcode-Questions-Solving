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
    int countPaths(TreeNode* root, long long targetSum) {
        if (!root) return 0;

        int count = 0;
        if (root->val == targetSum) count++;

        count += countPaths(root->left, targetSum - root->val);
        count += countPaths(root->right, targetSum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        return countPaths(root, targetSum) 
             + pathSum(root->left, targetSum) 
             + pathSum(root->right, targetSum);
    }
};
