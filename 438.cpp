class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> list;
      if (s.length() == 0 || p.length() == 0) return list;
      vector<int> hash(256, 0);
      for (char c : p) {
        hash[c]++;
      }
      int left = 0, right = 0, count = p.length();
      while (right < s.length()) {
        if (hash[s[right++]]-- >= 1) count--; 
        if (count == 0) list.push_back(left);
        if (right - left == p.length() && hash[s[left++]]++ >= 0) count++;
      }
      return list;
    }
};
