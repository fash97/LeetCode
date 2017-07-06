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
    string tree2str(TreeNode* t) {
      if(t==NULL) return "";
      string left_subtree = tree2str(t->left);
      string right_subtree = tree2str(t->right);
      if(left_subtree!="" && right_subtree!="") return to_string(t->val)+ "(" + left_subtree + ")" + "(" + right_subtree + ")";
      else if(left_subtree!="") return to_string(t->val)+ "(" + left_subtree + ")";
      else if(right_subtree!="")    return to_string(t->val)+"()"+"("+right_subtree+")";
      else    return to_string(t->val);
    }
};
