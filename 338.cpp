class Solution {
  public:
    vector<int> countBits(int num) {
      vector<int> result(num+1, 0);
      for(int i=0; i<=num; i++){
        result[i] = count(i);
      }
      return result;
    }

    int count(int n)
    {
      int count = 0;
      while (n)
      {
        count++;
        n = (n - 1) & n;
      }
      return count;
    }
};
