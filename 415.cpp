class Solution {
  public:
    string addStrings(string num1, string num2) {
      int idx_1 = num1.length()-1;
      int idx_2 = num2.length()-1;
      int c_in = 0;
      int c_out = 0;
      string result = "";
      while(idx_1 >= 0 && idx_2 >= 0){
        result = (char)(((num1[idx_1]-'0'+num2[idx_2]-'0'+c_in)%10)+'0') + result;
        c_out = (num1[idx_1]-'0'+num2[idx_2]-'0'+c_in)/10;
        c_in = c_out;
        idx_1--;
        idx_2--;
      }
      if(idx_1 >= 0){
        while(idx_1 >= 0 || c_in == 1){
          if(idx_1 < 0){
            result = "1" + result;
            break;
          }
          result = (char)(((num1[idx_1]-'0'+c_in)%10)+'0') + result;
          c_out = (num1[idx_1]-'0'+c_in)/10;
          c_in = c_out;
          idx_1--;
        }
      }
      else if(idx_2 >= 0){
        while(idx_2 >= 0 || c_in == 1){
          if(idx_2 < 0){
            result = "1" + result;
            break;
          }
          result = (char)(((num2[idx_2]-'0'+c_in)%10)+'0') + result;
          c_out = (num2[idx_2]-'0'+c_in)/10;
          c_in = c_out;
          idx_2--;
        }
      }
      else if(c_out == 1){
        result = "1" + result;
      }
      return result;
    }
};
