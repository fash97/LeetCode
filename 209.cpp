class Solution {
  public:
    int minSubArrayLen(int s, vector<int>& nums) {
      int start = 0, end = 0, sum = 0, min_length = INT_MAX;
      while(end < nums.size()){
        sum += nums[end++];
        while(sum >= s){
          min_length = min(min_length, end-start);
          sum -= nums[start++];
        }
      }
      return (min_length == INT_MAX) ? 0 : min_length;
    }
};
