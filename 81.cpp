class Solution {
  public:
    bool search(vector<int>& nums, int target) {
      if(nums.empty())    return false;
      int low =0, high = nums.size()-1;
      while(low<high){
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return true;
        if(nums[mid]>nums[high]){
          if(nums[mid]>target && nums[low] <= target) high = mid;
          else low = mid + 1;
        }else if(nums[mid] < nums[high]){
          if(nums[mid]<target && nums[high] >= target) low = mid + 1;
          else high = mid;
        }else{
          high--;
        }

      }
      return nums[low] == target ? true : false;
    }
};
