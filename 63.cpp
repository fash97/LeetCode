class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> matrix (m, vector<int>(n, 0));
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          if(obstacleGrid[i][j] == 0){
            if(i-1 < 0 && j-1 >= 0)  matrix[i][j] = matrix[i][j-1];
            else if(i-1 >= 0 && j-1 < 0)    matrix[i][j] = matrix[i-1][j];
            else if(i-1 < 0 && j-1 < 0) matrix[i][j] = 1;
            else if(i-1 >= 0 && j-1 >= 0)   matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
          }
          else    matrix[i][j] = 0;
        }
      }
      return matrix[m-1][n-1];
    }
};
