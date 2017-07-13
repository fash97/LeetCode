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
  private:
    int total = 0;
  public:
    int pathSum(TreeNode* root, int sum) {
      if(root == NULL)    return 0;
      return find(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int find(TreeNode* root, int till, int sum){
      if(root == NULL)    return 0;
      return (till + root->val == sum) + find(root->left, till+root->val, sum) + find(root->right, till+root->val, sum);
    }
};
