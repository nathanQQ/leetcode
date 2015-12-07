/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Use of a Queue as temporary memory
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> que;
        TreeNode* p;
        
        if (!root)
            return result;
            
        que.push(root);
        que.push(NULL);
        
        while (!que.empty()) {
            //queue is not empty
            p = que.front();
            que.pop();
            if (p != NULL) {
                level.push_back(p->val);
                if (p->left)
                    que.push(p->left);
                if (p->right)
                    que.push(p->right);
            }
            else {
                result.push_back(level);
                level.clear();  //reset the 1D vector
                if (!que.empty()) {
                    que.push(NULL);
                }
            }
        }
        return result;
    }
};