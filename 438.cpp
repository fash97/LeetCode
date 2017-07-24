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
        //move right everytime, if the character exists in p's hash, decrease the count
        //current hash value >= 1 means the character is existing in p
        if (hash[s[right]] >= 1) {
          count--;
        }
        hash[s[right]]--;
        right++;

        //when the count is down to 0, means we found the right anagram
        //then add window's left to result list
        if (count == 0) {
          list.push_back(left);
        }
        //if we find the window's size equals to p, then we have to move left (narrow the window) to find the new match window
        //++ to reset the hash because we kicked out the left
        //only increase the count if the character is in p
        //the count >= 0 indicate it was original in the hash, cuz it won't go below 0
        if (right - left == p.length() ) {

          if (hash[s[left]] >= 0) {
            count++;
          }
          hash[s[left]]++;
          left++;

        }


      }
      return list;
    }
};
