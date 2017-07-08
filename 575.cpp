class Solution {
  public:
    int distributeCandies(vector<int>& candies) {
      int num_candies = candies.size()/2;
      unordered_set<int> cache(candies.begin(), candies.end());
      return min(num_candies, (int)cache.size());
    }
};
