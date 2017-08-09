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
    unordered_set<int> set;

  public:
    bool findTarget(TreeNode* root, int k) {
      if(root == NULL)    return false;
      else if(set.find(k-root->val) != set.end()) return true;
      else    set.insert(root->val);
      return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
