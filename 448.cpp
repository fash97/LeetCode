class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      vector<int> result;
      for(int i=0; i<nums.size(); i++){
        int idx = abs(nums[i])-1;
        nums[idx] = (nums[idx] < 0) ? nums[idx] : -nums[idx];
      }
      for(int i=0; i<nums.size(); i++){
        if(nums[i] > 0) result.push_back(i+1);
      }
      return result;
    }
};
