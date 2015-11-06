/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        if (!root)
            return paths;
        
        binaryTreePathsDFS(root, to_string(root->val), paths);
        
        return paths;

    }
    //depth first travers
    void binaryTreePathsDFS(TreeNode *root, string out, vector<string> &paths) {
        if (!root->left && !root->right) paths.push_back(out);
        if (root->left) {
            binaryTreePathsDFS(root->left, out + "->" + to_string(root->left->val), paths);
        }
        if (root->right) {
            binaryTreePathsDFS(root->right, out + "->" + to_string(root->right->val), paths);
        }
    }    
};