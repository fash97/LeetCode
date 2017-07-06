class Solution {
  public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> common;
      for(int i=0; i<list1.size(); i++){
        auto return_val = find(list2.begin(), list2.end(), list1[i]);
        if(return_val != list2.end()){
          cout << list1[i] << endl;
          cout << distance(list2.begin(), return_val)+i << endl;
          common.push(make_pair(distance(list2.begin(), return_val)+i, list1[i]));
        }
      }
      auto smallest = common.top();
      vector<string> result;
      result.push_back(smallest.second);
      common.pop();
      while(!common.empty() && common.top().first==smallest.first){
        result.push_back(common.top().second);
        common.pop();
      }
      return result;
    }
};
