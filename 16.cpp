class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int closest_number = 0;
      int difference = INT_MAX;
      for(int i=0; i<nums.size(); i++){
        int start = i + 1;
        int end = nums.size()-1;
        if(start == end)    break;
        int sum = 0;
        int local_difference = INT_MAX;
        int local_closest = 0;
        while(start < end){
          sum = nums[start] + nums[end];
          if(sum > target-nums[i])    end--;
          else if(sum < target-nums[i])   start++;
          else    return target;
          if(abs(sum+nums[i]-target) < local_difference){
            local_difference = abs(sum+nums[i]-target);
            local_closest = sum+nums[i];
          }
        }
        if(local_difference < difference){
          closest_number = local_closest;
          difference = local_difference;
        }
      }
      return closest_number;
    }
};
