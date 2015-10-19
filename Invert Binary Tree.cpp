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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* tmpNode = NULL;
        if (root == NULL)
            return NULL;
        tmpNode = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpNode);
        return root;
    }
};