class Solution {
  public:
    bool detectCapitalUse(string word) {
      if(word.length()==1)   return true;
      int case_num = -1;
      if(isupper(word[0]) && isupper(word[1]))    case_num = 1;
      else if(islower(word[0]))   case_num = 2;
      else if(isupper(word[0]) && islower(word[1]))   case_num = 3;
      else    return false;
      if(case_num == 1){
        for(int i=0; i<word.length(); i++){
          if(islower(word[i]))    return false;
        }
        return true;
      }
      else if(case_num == 2){
        for(int i=0; i<word.length(); i++){
          if(isupper(word[i]))    return false;
        }
        return true;
      }
      else{
        for(int i=1; i<word.length(); i++){
          if(isupper(word[i]))    return false;
        }
        return true;
      }
      return false;
    }
};
