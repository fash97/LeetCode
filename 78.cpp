class Solution {
  public:
    vector<vector<int>> subsets(vector<int>& nums) {
      //List to store the final result
      vector<vector<int>> list;
      //Calculate the size of the power set
      unsigned int pow_size = pow(2, nums.size());
      //Counter is for looping through every possible combination
      //j is a binary magic idenfier
      //For example, 110 means that take the first element in nums
      //and second element in nums without taking the third
      int counter, j;
      //From all possible solution
      for(counter = 0; counter < pow_set_size; counter++)
      {
        vector<int> temp_list;
        //Check the idenfier
        for(j = 0; j < nums.size(); j++)
        {
          //If the digit is 1, then take it
          if(counter & (1<<j))
            temp_list.push_back(nums[j]);
        }
        //Push the whole set
        list.push_back(temp_list);
      }
      return list;
    }
};
