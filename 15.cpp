class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> local;
      for(int i=0; i<nums.size(); i++){
        int start = i+1;
        int end = nums.size()-1;
        int target = -nums[i];
        while(start < end){
          int sum = nums[start] + nums[end];
          if(sum < target)    start++;
          else if(sum > target)   end--;
          else{
            vector<int> tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[start]);
            tmp.push_back(nums[end]);
            local.push_back(tmp);
            while(start < end && nums[start] == tmp[1]) start++;
            while(start < end && nums[end] == tmp[2])   end--;
          }
        }
        while(i+1 < nums.size() && nums[i+1]==nums[i])   i++;
      }

      return local;
    }
};
