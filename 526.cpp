class Solution {
  public:
    int countArrangement(int N) {
      vector<int> tempList;
      vector<vector<int>> result;
      buildBeautiful(result, tempList, 1, N);
      return result.size();
    }

    void buildBeautiful(vector<vector<int>> &result, vector<int> tempList, int start, int end){
      if(start > end ){
        result.push_back(tempList);
        return;
      }
      for(int i=1; i<=end; i++){
        if(((tempList.size()+1)%i) != 0 && (i%(tempList.size()+1)) != 0)    continue;
        else if(find(tempList.begin(), tempList.end(), i) != tempList.end())    continue;
        tempList.push_back(i);
        buildBeautiful(result, tempList, start+1, end);
        tempList.pop_back();
      }
    }
};
