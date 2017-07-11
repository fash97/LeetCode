class Solution {
  public:
    int thirdMax(vector<int>& nums) {
      set<int, greater<int>> local;
      for(int num : nums){
        local.insert(num);
      }
      if(local.size() < 3)    return *local.begin();
      else    return *(++++local.begin());
    }
};
