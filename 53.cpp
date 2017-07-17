class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
      int previous_sum = 0;
      int max_val = INT_MIN;
      for(int i=0; i<nums.size(); i++){
        if(previous_sum < 0)    previous_sum = nums[i];
        else    previous_sum = previous_sum + nums[i];
        max_val = max(previous_sum, max_val);
      }
      return max_val;
    }
};
