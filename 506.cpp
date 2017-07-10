class Solution {
  public:
    vector<string> findRelativeRanks(vector<int>& nums) {
      vector<int> sorted = nums;
      unordered_map<int, string> local;
      sort(sorted.begin(), sorted.end(), greater<int>());
      for(int i=0; i<sorted.size(); i++){
        if(i == 0)  local.insert(make_pair(sorted[i], "Gold Medal"));
        else if(i == 1) local.insert(make_pair(sorted[i], "Silver Medal"));
        else if(i == 2) local.insert(make_pair(sorted[i], "Bronze Medal"));
        else local.insert(make_pair(sorted[i], to_string(i+1)));
      }
      vector<string> result;
      for(int num : nums){
        result.push_back(local.find(num)->second);
      }
      return result;
    }
};
