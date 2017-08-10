/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
  public:
    void connect(TreeLinkNode *root) {
      if(!root)   return;
      queue<pair<TreeLinkNode*, int>> q;
      pair<TreeLinkNode*, int> previous = make_pair(nullptr, 0);
      q.push(make_pair(root, 0));
      while(!q.empty()){
        auto top_e = q.front();
        q.pop();
        if(top_e.first != NULL){
          q.push(make_pair(top_e.first->left, top_e.second+1));
          q.push(make_pair(top_e.first->right, top_e.second+1));
        }
        if(previous.first != NULL && previous.second==top_e.second)    previous.first->next = top_e.first;
        previous = top_e;
      }
    }
};

/* Recommended solution
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
*/
