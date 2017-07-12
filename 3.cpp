class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int maximum = 0;
      vector<int> map(256, -1);
      for(int i=0, j=0; i<s.length(); i++){
        if(map[s[i]] != -1) j = max(j, map[s[i]]+1);
        map[s[i]] = i;
        maximum = max(i-j+1, maximum);
      }
      return maximum;
    }
};
