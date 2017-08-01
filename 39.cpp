class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> result;
      vector<int> tempList;
      helper(result, tempList, candidates, target, 0);
      return result;
    }

    void helper(vector<vector<int>> &result, vector<int> tempList, vector<int> candidates, int remain, int start){
      if(remain < 0)  return;
      else if(remain == 0)    result.push_back(tempList);
      else{
        for(int i=start; i<candidates.size(); i++){
          tempList.push_back(candidates[i]);
          helper(result, tempList, candidates, remain-candidates[i], i);
          tempList.pop_back();
        }
      }
    }
};
