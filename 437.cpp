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
      find(root, sum);
      return total;
    }

    void find(TreeNode* root, int sum){
      if(root==NULL)  return;
      pathSum(root, 0, sum);
      find(root->left, sum);
      find(root->right, sum);
    }

    void pathSum(TreeNode* root, int tillnow, int sum){
      if(root == NULL)    return;
      if(tillnow + root->val == sum)  total++;
      pathSum(root->left, tillnow+root->val, sum);
      pathSum(root->right, tillnow+root->val, sum);
    }
};
