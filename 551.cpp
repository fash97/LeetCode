class Solution {
  public:
    bool checkRecord(string s) {
      int num_A = 0;
      int num_L = 0;
      char previous = '?';
      for(int i=0; i<s.length(); i++){
        if(s[i]=='A'){
          num_A++;
          previous='A';
        }
        else if(s[i]=='L' && previous=='L') num_L++;
        else if(s[i]=='L' && previous!='L') num_L=1;
        if(num_L > 2 || num_A > 1)   return false;
        previous = s[i];
      }
      return true;
    }
};
