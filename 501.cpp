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
    unordered_map<int, int> map;

  public:
    vector<int> findMode(TreeNode* root) {
      int max = 0;
      traverse(root);
      vector<int> local;
      for(auto i = map.begin(); i != map.end(); i++){
        cout << (*i).second << endl;
        if((*i).second > max){
          max = (*i).second;
          local.clear();
          local.push_back((*i).first);
        }
        else if((*i).second == max){
          local.push_back((*i).first);
        }
      }
      return local;
    }

    void traverse(TreeNode* root){
      if(root == NULL)    return;
      auto returned_val = map.insert(make_pair(root->val, 1));
      if(!returned_val.second)   map[root->val]++;
      traverse(root->left);
      traverse(root->right);
    }
};
