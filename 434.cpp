class Solution {
  public:
    int countSegments(string s) {
      if(s.empty())   return 0;
      int count = 0;
      for(int i=0; i<s.length()-1; i++)   if((int)(s[i]) >= 33  && (int)(s[i+1]) < 33)  count++;
      if((int)(s[s.length()-1]) >= 33 )   count++;
      return count;
    }
};
