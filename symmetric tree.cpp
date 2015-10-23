/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
       if (!root)
            return true;
        return isSymmetricTree(root->left, root->right);
    }
    bool isSymmetricTree(TreeNode* lNode, TreeNode* rNode) {
        if (!lNode) {
            return (rNode == NULL);
        }
        if (!rNode) {
            return (lNode == NULL);
        }
        if (lNode->val != rNode->val) {
            return false;
        }
        if (!isSymmetricTree(lNode->left, rNode->right)) {
            return false;
        }
        if (!isSymmetricTree(lNode->right, rNode->left)) {
            return false;
        }
        return true;
        
    }
};