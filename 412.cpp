class Solution {
  public:
    vector<string> fizzBuzz(int n) {
      vector<string> local;
      int i = 1;
      while(i <= n){
        string tmp = "";
        if(i%3==0)  tmp += "Fizz";
        if(i%5==0) tmp += "Buzz";
        if(tmp.empty()) tmp += to_string(i);
        local.push_back(tmp);
        i++;
      }
      return local;
    }
};
