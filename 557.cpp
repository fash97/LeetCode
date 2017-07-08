class Solution {
  public:
    string reverseWords(string s) {
      string reversed = "";
      stack<char> local;
      for(char c : s){
        if(c != ' ')    local.push(c);
        else if(c == ' '){
          while(!local.empty()){
            reversed+=local.top();
            local.pop();
          }
          reversed+=' ';
        }
      }
      while(!local.empty()){
        reversed+=local.top();
        local.pop();
      }
      return reversed;
    }
};
