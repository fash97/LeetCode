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
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
    int helper(TreeNode* root, bool left){
        if(root && !root->left && !root->right && left) return root->val;
        else if(!root)  return 0;
        return helper(root->left, true)+helper(root->right, false);
    }
};
