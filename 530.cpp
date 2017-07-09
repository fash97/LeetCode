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
    int getMinimumDifference(TreeNode* root) {
      if(root == NULL)    return 0;
      vector<int> local;
      queue<TreeNode*> q;
      int smallest = INT_MAX;
      q.push(root);
      while(!q.empty()){
        TreeNode* tmp = q.front();
        local.push_back(tmp->val);
        q.pop();
        if(tmp->left)  q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
      }
      sort(local.begin(), local.end());
      for(int i=0; i<local.size(); i++){
        int j=i+1;
        while(local[j]==local[i])   j++;x
          if(j >= local.size())   continue;
          else    smallest = min(smallest, abs(local[j]-local[i]));
      }
      return smallest;
    }
};
