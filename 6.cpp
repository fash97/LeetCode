class Solution {
  public:
    string convert(string s, int numRows) {
      if(numRows == 1)    return s;
      vector<string> local(numRows, "");
      int i=0;
      bool zig = true;
      int idx = 0;
      for(int i=0; i<s.length(); i++){
        local[idx] = local[idx]+s[i];
        if(zig) idx++;
        else    idx--;
        if(zig && idx > numRows-1){
          zig = false;
          idx = numRows-2;
          if(idx == 0){
            zig = true;
            idx = 0;
          }
        }
        else if(!zig && idx <= 0){
          zig = true;
          idx = 0;
        }
      }
      string result = "";
      for(string str : local) result += str;
      return result;
    }
};
