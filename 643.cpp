class Solution {
  public:
    double findMaxAverage(vector<int>& nums, int k) {
      int max_val = INT_MIN;
      int sum = 0;
      for(int i=0; i<k; i++){
        sum += nums[i];
      }
      max_val = max(sum, max_val);
      for(int i=1; i<=nums.size()-k; i++){
        int j = i;
        sum = sum - nums[i-1] + nums[i+k-1];
        max_val = max(sum, max_val);
      }
      return (double)(max_val)/k;
    }
};
