class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
      unordered_map<int, int> nums_map;
      vector<int> local;
      for(int i=0; i<nums.size(); i++){
        nums_map.insert(make_pair(nums[i], i));
      }
      for(int i=0; i<findNums.size(); i++){
        bool find =false;
        for(int j = nums_map[findNums[i]]; j<nums.size(); j++){
          if(nums[j] > findNums[i]){
            local.push_back(nums[j]);
            find = true;
            break;
          }
        }
        if(!find)   local.push_back(-1);
      }
      return local;
    }
};
