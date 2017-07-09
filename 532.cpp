class Solution {
  public:
    int findPairs(vector<int>& nums, int k) {
      map<int, int> m;
      int count = 0;
      for(int num : nums){
        auto ret = m.find(num);
        if(ret != m.end())  ret->second++;
        else    m.insert(make_pair(num, 1));
      }
      if(k!=0){
        for(auto i=m.begin(); i!=m.end(); i++){
          auto j = i;
          while(j != m.end()){
            if(j->first-i->first == k)  count++;
            else if(j->first-i->first > k)  break;
            j++;
          }
        }
      }
      else    for(auto element : m)   if(element.second > 1) count++;
      return count;
    }
};
