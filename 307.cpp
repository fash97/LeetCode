struct MyTreeNode{
  int val;
  int start;
  int end;
  MyTreeNode* left;
  MyTreeNode* right;
  MyTreeNode(int v, int s, int e): val(v), start(s), end(e), left(nullptr), right(nullptr) {}
};

class NumArray {
  private:
    MyTreeNode* root;

  public:
    NumArray(vector<int> nums) {
      if(nums.empty())    root == nullptr;
      else    root = buildTree(nums, root, 0, nums.size()-1);
    }

    void update(int i, int val) {
      if(!root)   return;
      updateVal(root, i, val);
    }

    int sumRange(int i, int j) {
      if(!root)   return 0;
      //printTree(root);
      return findSum(root, i, j);
    }

    MyTreeNode* buildTree(vector<int> nums, MyTreeNode* root, int start, int end){
      if(start > end){
        return nullptr;
      }
      if(start == end){
        return new MyTreeNode(nums[start], start, end);
      }
      root = new MyTreeNode(0, start, end);
      int mid = start + (end-start)/2;
      root->left = buildTree(nums, root->left, start, mid);
      root->right = buildTree(nums, root->right, mid+1, end);
      root->val = root->left->val + root->right->val;
      return root;
    }

    void printTree(MyTreeNode* curr){
      if(curr == nullptr) return;
      cout << curr->val;
      cout << "[" ;
      printTree(curr->left);
      cout << "," ;
      printTree(curr->right);
      cout << "]" ;
    }

    int updateVal(MyTreeNode* current, int i, int val){
      int start = current->start;
      int end = current->end;
      if(start == i && end == i){
        int difference = val - current->val;
        current->val = val;
        return difference;
      }
      else if(start == end)   return 0;
      int mid = start + (end-start)/2;
      int diff;
      if(i > mid) diff = updateVal(current->right, i, val);
      else    diff = updateVal(current->left, i, val);
      current->val += diff;
      return diff;
    }

    int findSum(MyTreeNode* current, int start, int end){
      if(current == nullptr)  return 0;
      int curr_s = current->start;
      int curr_e = current->end;
      if(curr_s == start && curr_e == end)  return current->val;
      int mid = curr_s + (curr_e - curr_s)/2;
      if(end <= mid)  return findSum(current->left, start, end);
      else if(start > mid)    return findSum(current->right, start, end);
      else return findSum(current->left, start, mid)+findSum(current->right, mid+1, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
