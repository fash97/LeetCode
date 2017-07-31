class Solution {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      set<vector<int>> result;
      sort(nums.begin(), nums.end());
      helper(result, nums, 0, nums.size()-1);
      vector<vector<int>> final(result.begin(), result.end());
      return final;
    }

    void helper(set<vector<int>> &result, vector<int>& nums, int l, int r){
      int i;
      if(l == r){
        result.insert(nums);
      }
      else{
        for (i = l; i <= r; i++){
          swap(nums[l], nums[i]);
          helper(result, nums, l+1, r);
          swap(nums[l], nums[i]);
        }
      }
    }
};
