class Solution {
  public:
    int search(vector<int>& nums, int target) {
      if(nums.empty())    return -1;
      int low = 0, high = nums.size()-1;
      while(low < high){
        int mid = low + (high-low)/2;
        if(nums[mid] > nums[high])  low = mid+1;
        else    high = mid;
      }
      int shift = low;
      low = 0, high = nums.size()-1;
      while(low <= high){
        int mid = low + (high-low)/2;
        int mid_after_shift = (mid + shift) % nums.size();
        if(nums[mid_after_shift] == target) return mid_after_shift;
        else if(nums[mid_after_shift] > target) high = mid-1;
        else    low = mid+1;
      }
      return -1;
    }
};
