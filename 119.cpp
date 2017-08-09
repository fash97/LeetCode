class Solution {
  public:
    vector<int> getRow(int rowIndex) {
      vector<int> previous;
      for(int i=1; i<=rowIndex+1; i++){
        vector<int> current(i, 0);
        current[0] = 1;
        current[i-1] = 1;
        int idx = 0;
        for(int j=1; j<i-1; j++){
          current[j] = previous[idx]+previous[++idx];
        }
        previous = current;
      }
      return previous;
    }
};
