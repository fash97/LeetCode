class Solution {
  public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      bool previous_planted = false;
      int aval = 0;
      for(int i=0; i<flowerbed.size()-1; i++){
        if(flowerbed[i]==0 && !previous_planted && flowerbed[i+1]!=1){
          aval++;
          previous_planted = true;
        }
        else if(flowerbed[i]==0 && previous_planted)    previous_planted = false;
        else if(flowerbed[i]==1)    previous_planted = true;
      }
      if(flowerbed[flowerbed.size()-1]==0 && !previous_planted)   aval++;
      return (n<=aval)?true:false;
    }
};
