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
    int sum = 0;

  public:
    void deepLearn(TreeNode* root){
      if(root == NULL) return;
      deepLearn(root->right);
      root->val += sum;
      sum = root->val;
      deepLearn(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
      deepLearn(root);
      return root;
    }
};
