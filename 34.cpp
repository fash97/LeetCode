class Solution {
  public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> found(2, 0);
      int min = 0;
      int max = nums.size()-1;
      while(min <= max){
        int mid = min + (max-min)/2;
        if(nums[mid] == target){
          int low = mid;
          int high = mid;
          while(low >= 0 && nums[low]==nums[mid]){
            low--;
          }
          while(high < nums.size() && nums[high]==nums[mid]){
            high++;
          }
          found[0] = ++low;
          found[1] = --high;
          return found;
        }
        else if(nums[mid] < target){
          min = mid + 1;
        }
        else{
          max = mid - 1;
        }
      }
      found[0] = -1;
      found[1] = -1;
      return found;
    }
};
