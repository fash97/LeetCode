class Solution {
  public:
    string convertToBase7(int num) {
      int result = 0;
      int degree = 1;
      while(num != 0){
        int tmp = num % 7;
        result = degree*tmp + result;
        degree *= 10;
        num /= 7;
      }
      return to_string(result);
    }
};
