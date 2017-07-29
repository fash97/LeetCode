class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int count = 0, max_val = INT_MIN;
      bool previous = false;
      for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1 && previous)    count++;
        else if(nums[i] == 1 && !previous){
          previous = true;
          count = 1;
        }
        else{
          previous = false;
          max_val = max(max_val, count);
          count = 0;
        }
      }
      return max(max_val, count);
    }
};
