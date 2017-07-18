class Solution {
  public:
    vector<string> generateParenthesis(int n) {
      unordered_set<string> local;
      vector<string> dict;
      if(n == 0){
        return dict;
      }
      else if(n == 1){
        dict.push_back("()");
        return dict;
      }
      else{
        dict = generateParenthesis(n-1);
        for(int i=0; i<dict.size(); i++){
          for(int j=0; j<dict[i].length(); j++){
            local.insert(dict[i].substr(0, j)+"()"+dict[i].substr(j, dict[i].length()-j));
          }
        }
        dict.clear();
      }
      std::copy(local.begin(), local.end(), std::back_inserter(dict));
      return dict;
    }
};
