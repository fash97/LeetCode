class Solution {
  public:
    int findUnsortedSubarray(vector<int>& nums) {
      int begin = -1;
      int end = -2;
      int left_max = nums[0];
      int right_min = nums[nums.size()-1];
      for(int i=1; i<nums.size(); i++){
        left_max = max(nums[i], left_max);
        right_min = min(nums[nums.size()-1-i], right_min);
        end = (nums[i]<left_max)?i:end;
        begin = (nums[nums.size()-1-i]>right_min)?nums.size()-1-i:begin;
      }
      return end-begin+1;
    }
};
