class Solution {
  public:
    vector<int> constructRectangle(int area) {
      int root = (int)(sqrt(area));
      while(area%root!=0)   root--;
      vector<int> local;
      local.push_back(area/root);
      local.push_back(root);
      return local;
    }
};
