class Solution {
  public:
    int longestPalindrome(string s) {
      int lower_alphabet[26] = {0};
      int upper_alphabet[26] = {0};
      int even_char = 0;
      int odd_char = 0;
      for(char c : s){
        if(isupper(c))  upper_alphabet[c-'A']++;
        else    lower_alphabet[c-'a']++;
      }
      for(int i=0; i<26; i++){
        even_char+=lower_alphabet[i]/2;
        odd_char+=lower_alphabet[i]%2;
      }
      for(int i=0; i<26; i++){
        even_char+=upper_alphabet[i]/2;
        odd_char+=upper_alphabet[i]%2;
      }
      if(odd_char != 0)   return even_char*2+1;
      else    return even_char*2;
    }
};
