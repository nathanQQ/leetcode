/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (abs(depth(root->left) - depth(root->right)) > 1)
            return false;
        else
            return (isBalanced(root->left) && isBalanced(root->right));
    }
    
    int depth(TreeNode* node) {
        if (!node)
            return 0;
        return (1 + max(depth(node->left), depth(node->right)));
    }
};