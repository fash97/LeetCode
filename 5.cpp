class Solution {
  public:
    string longestPalindrome(string s) {
      if(s.length() == 0)  return 0;
      string reversed = s;
      reverse(reversed.begin(), reversed.end());
      int idx1 = 0;
      int idx2 = 0;
      int max = 0;
      vector<vector<int>> matrix (s.length(), vector<int>(s.length(),0));
      for (int i = 0; i < s.length(); i++) {
        for (int j=0; j < reversed.length(); j++) {
          if(s[i] == reversed[j]){
            if(i-1 < 0 || j-1 < 0)  matrix[i][j] = 1;
            else    matrix[i][j] = matrix[i-1][j-1] + 1;
          }
        }
      }
      for(int i=0; i<s.length(); i++){
        for(int j=0; j<reversed.length(); j++){
          if(matrix[i][j] > max && i>=j && (s.length()-(i-matrix[i][j]+1)-1)==j){
            max = matrix[i][j];
            idx1 = i;
            idx2 = j;
          }
          else if(matrix[i][j] > max && i<j && (s.length()-(j-matrix[i][j]+1)-1)==i){
            max = matrix[i][j];
            idx1 = i;
            idx2 = j;
          }

        }
      }
      string local = "";
      while(idx1 >= 0 && idx2 >= 0 && matrix[idx1][idx2--] != 0){
        local = s[idx1--] + local ;
      }
      return local;
    }
};
