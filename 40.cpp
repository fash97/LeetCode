class Solution {
  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      set<vector<int>> result;
      vector<int> tempList;
      helper(result, tempList, candidates, target, 0);
      vector<vector<int>> final_result(result.begin(), result.end());
      return final_result;
    }

    void helper(set<vector<int>> &result, vector<int> tempList, vector<int> candidates, int remain, int start){
      if(remain < 0)  return;
      else if(remain == 0)    result.insert(tempList);
      else{
        for(int i=start; i<candidates.size(); i++){
          tempList.push_back(candidates[i]);
          helper(result, tempList, candidates, remain-candidates[i], i+1);
          tempList.pop_back();
        }
      }
    }
};
