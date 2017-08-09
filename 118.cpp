class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> result;
      if(numRows == 0)    return result;
      vector<int> previous;
      for(int i=1; i<=numRows; i++){
        vector<int> current(i, 0);
        current[0] = 1;
        current[i-1] = 1;
        int idx = 0;
        for(int j=1; j<i-1; j++){
          current[j] = previous[idx]+previous[++idx];
        }
        result.push_back(current);
        previous = current;
      }
      return result;
    }
};
