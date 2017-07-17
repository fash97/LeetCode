class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
      vector<vector<int>> matrix (grid.size(), vector<int> (grid[0].size(), 0));
      int min_val = 0;
      for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
          if(i-1 < 0 && j-1 >= 0) matrix[i][j] = matrix[i][j-1] + grid[i][j];
          else if(i-1 >= 0 && j-1 < 0)    matrix[i][j] = matrix[i-1][j] + grid[i][j];
          else if(i-1 < 0 && j-1 < 0)   matrix[i][j] = grid[i][j];
          else if(i-1 >= 0 && j-1 >= 0)  matrix[i][j] = min(matrix[i][j-1], matrix[i-1][j]) + grid[i][j];
        }
      }
      return matrix[grid.size()-1][grid[0].size()-1];
    }
};
