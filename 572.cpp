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

    bool isSubtree(TreeNode* s, TreeNode* t) {
      if(!s && !t)    return true;
      else if(!s && t || s && !t)    return false;
      return same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool same(TreeNode* s, TreeNode* t){
      if(!s && !t)    return true;
      else if((s && !t) || (!s && t) || s->val != t->val)    return false;
      else if(!s->left && !s->right && !t->left && !t->right && s->val==t->val)  return true;
      return same(s->left, t->left)&&same(s->right, t->right);
    }
};
