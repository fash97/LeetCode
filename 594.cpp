class Solution {
  public:
    int findLHS(vector<int>& nums) {
      if(nums.empty())    return 0;
      sort(nums.begin(), nums.end());
      int first = nums[0];
      int second = INT_MIN;
      int count_1 = 1;
      int count_2 = 0;
      int max_val = 0;
      for(int i=1; i<nums.size(); i++){
        if(nums[i]==first)  count_1++;
        else if(nums[i]!=first && second==INT_MIN){
          count_2++;
          second=nums[i];
        }
        else if(nums[i]!=first && second!=INT_MIN && nums[i]==second)   count_2++;
        else{
          max_val = (second-first==1)?max(max_val, count_1+count_2):max_val;
          count_1 = count_2;
          count_2 = 1;
          first = second;
          second = nums[i];
        }
      }
      if(second-first==1) max_val = max(max_val, count_1+count_2);
      return max_val;
    }
};
