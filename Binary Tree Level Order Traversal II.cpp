/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> que;
        TreeNode* tmpNode;
        
        if (!root) 
            return result;
        que.push(root);
        que.push(NULL);
        
        while (!que.empty()) {
            tmpNode = que.front();
            que.pop();
            
            if (tmpNode) {
                level.push_back(tmpNode->val);
                if (tmpNode->left)
                    que.push(tmpNode->left);
                if (tmpNode->right)
                    que.push(tmpNode->right);
            }
            else {
                result.push_back(level);
                level.clear();
                if (!que.empty()) {
                    que.push(NULL);
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};