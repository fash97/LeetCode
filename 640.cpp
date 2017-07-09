class Solution {
  public:
    string solveEquation(string equation) {
      bool plus = true;
      bool digit_before = false;
      bool after_equal=false;
      int digits = 0;
      int num_x = 0;
      int num = 0;
      for(int i=0; i<equation.length(); i++){
        if(equation[i]=='x'){
          if(digit_before && plus)    num_x+=digits;
          else if(digit_before && !plus)  num_x-=digits;
          else if(!digit_before && plus)  num_x++;
          else    num_x--;
          digit_before = false;
          digits = 0;
        }
        else if(isdigit(equation[i])){
          digit_before = true;
          digits = digits*10 + (equation[i]-'0');
        }
        else if(equation[i]=='+' || equation[i]=='-' || equation[i]=='='){
          if(digit_before && plus)    num+=digits;
          else if(digit_before && !plus)  num-=digits;
          if(equation[i]=='-')    plus=(after_equal)?true:false;
          else if(equation[i]=='='){
            after_equal=true;
            plus=false;
          }
          else    plus=(after_equal)?false:true;
          digit_before = false;
          digits = 0;
        }
      }
      if(digit_before && plus)    num+=digits;
      else if(digit_before && !plus)  num-=digits;
      if(num_x==0 && num!=0)    return "No solution";
      else if(num_x==0 && num==0) return "Infinite solutions";
      return "x="+to_string((-num)/(num_x));
    }
};
