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
    int findTilt(TreeNode* root) {
      if(root == NULL)    return 0;
      int left = findTilt(root->left);
      int right = findTilt(root->right);
      return left + right + abs(sum(root->left)-sum(root->right));
    }

    int sum(TreeNode* root){
      if(root==NULL)  return 0;
      else if(!root->left && !root->right)    return root->val;
      return sum(root->left)+sum(root->right)+root->val;
    }
};
