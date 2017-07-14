class Solution {
  public:
    vector<string> findWords(vector<string>& words) {
      regex e1("[qwertyuiopQWERTYUIOP]*");
      regex e2("[asdfghjklASDFGHJKL]*");
      regex e3("[zxcvbnmZXCVBNM]*");
      vector<string> local;
      for(string word : words){
        if(regex_match(word, e1) || regex_match(word, e2) || regex_match(word, e3)){
          local.push_back(word);
        }
      }
      return local;
    }
};
