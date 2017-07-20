class Solution {
  public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.empty() || matrix[0].empty())  return false;
      int min = 0;
      int max = matrix.size()*matrix[0].size();
      while(min <= max){
        int mid = min + (max-min)/2;
        int row = mid/matrix[0].size();
        int column = mid%matrix[0].size();
        if(row >= matrix.size() || column > matrix[0].size()){
          return false;
        }
        int current = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
        if(current == target){
          return true;
        }
        else if(current < target){
          min = mid + 1;
        }
        else{
          max = mid - 1;
        }
      }
      return false;
    }
};
