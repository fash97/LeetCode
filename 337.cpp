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
    int rob(TreeNode* root) {
      if(!root)   return 0;
      int money = 0;
      if(root->left){
        money += rob(root->left->left) + rob(root->left->right);
      }
      if(root->right){
        money += rob(root->right->left) + rob(root->right->right);
      }
      //Compare rob this node + the grandchildren with rob the children of this node
      return max(val+root->val, rob(root->left)+rob(root->right));
    }
};
