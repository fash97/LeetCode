class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if(s.empty())   return 0;
      vector<int> map(256, -1);
      int start = 0, end = 0, max_val = INT_MIN;
      while(end < s.length()){
        if(map[s[end]] != -1 && map[s[end]] >= start){
          max_val = max(max_val, end-start);
          start = map[s[end]]+1;
        }
        map[s[end]] = end;
        end++;
      }
      return max(max_val, end-start);
    }
};
