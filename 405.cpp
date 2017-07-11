class Solution {
  public:
    string toHex(int num) {
      if(num == 0)    return "0";
      char alphabet[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
      uint32_t mask = 15;
      int count = 0;
      string result = "";
      while(mask != 0){
        result = alphabet[(num&mask)>>count] + result;
        mask = mask << 4;
        count += 4;
      }
      return result.substr(result.find_first_not_of('0'), result.length()-result.find_first_not_of('0'));
    }
};
