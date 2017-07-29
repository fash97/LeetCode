class Solution {
  public:
    int countSubstrings(string s) {
      int count = 0;
      if(s.length()==0)   return 0;  
      vector<vector<bool>> palin(s.length(), vector<bool>(s.length(), false));  
      string res = "";  
      for(int i=s.length()-1;i>=0;i--)  
      {  
        for(int j=i;j<s.length();j++)  
        {  
          if((s[i]==s[j]) && (j-i<=2 || palin[i+1][j-1]))  
          {  
            palin[i][j] = true;  
            count++;  
          }  
        }  
      }  
      return count;
    }
};
