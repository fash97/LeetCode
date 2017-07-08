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
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root || (!root->left && !root->right))    return 0;
      int dis = height(root->left)+height(root->right)+2;
      int sub_dis = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
      return max(dis,sub_dis);
    }

    int height(TreeNode* root){
      if(!root)   return -1;
      return max(height(root->left), height(root->right))+1;
    }
};
