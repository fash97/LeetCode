class Solution {
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      helper(result, nums, 0, nums.size()-1);
      return result;
    }

    void helper(vector<vector<int>> &result, vector<int>& nums, int l, int r){
      int i;
      if(l == r){
        result.push_back(nums);
      }
      else{
        for (i = l; i <= r; i++){
          //Swap
          swap(nums[l], nums[i]);
          helper(result, nums, l+1, r);
          //Swap back
          swap(nums[l], nums[i]);
        }
      }
    }
};
