class Solution {
  public:
    string reverseStr(string s, int k) {
      for(int i=0; i<s.length(); i+=2*k){
        int min=i;
        int max=((i+k-1)>s.length()-1)?s.length()-1:i+k-1;
        while(min < max)    swap(s[min++], s[max--]);
      }
      return s;
    }
};
