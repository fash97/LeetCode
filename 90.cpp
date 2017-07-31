class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      //Use set to avoid duplicate element
      set<vector<int>> list_unique;
      unsigned int pow_set_size = pow(2, nums.size());
      int counter, j;

      for(counter = 0; counter < pow_set_size; counter++)
      {
        vector<int> temp_list;
        for(j = 0; j < nums.size(); j++)
        {
          if(counter & (1<<j))
            temp_list.push_back(nums[j]);
        }
        list_unique.insert(temp_list);
      }
      vector<vector<int>> list;
      for(auto element : list_unique){
        list.push_back(element);
      }
      return list;
    }
};
