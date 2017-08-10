class Solution {
  public:
    int rob(vector<int>& nums) {
      int money_robbed = 0;
      int money_robbed_before = 0;
      bool previous_robbed = false;
      for(int i=0; i<nums.size(); i++){
        if(previous_robbed && money_robbed_before+nums[i]>money_robbed){
          int tmp = money_robbed;
          money_robbed = money_robbed_before+nums[i];
          money_robbed_before = tmp;
        }
        else if(previous_robbed && money_robbed_before+nums[i]<=money_robbed){
          previous_robbed = false;
        }
        else{
          int tmp = money_robbed;
          money_robbed = money_robbed + nums[i];
          money_robbed_before = tmp;
          previous_robbed = true;
        }
      }
      return money_robbed;
    }
};
