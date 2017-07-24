class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if(s.empty())   return 0;
      vector<int> map(256, -1);
      int start = 0, end = 0, longest = INT_MIN;
      while(start < s.length() && end < s.length()){
        if(map[s[end]] != -1 && map[s[end]] >= start){
          cout << "start: " << start << endl;
          cout << "end: " << end << endl;
          longest = max(longest, end-start);
          start = map[s[end]] + 1;
          map[s[end]] = end;
        }
        else if(map[s[end]] != -1 && map[s[end]] < start){
          map[s[end]] = end;
        }
        else{
          map[s[end]] = end;
        }
        end++;
      }
      return max(longest, end-start);
    }
};
