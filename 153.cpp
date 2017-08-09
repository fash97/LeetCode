class Solution {
  public:
    int findMin(vector<int>& nums) {
      int start=0,end=nums.size()-1;
      while (start<end) {
        //如果nums[start] < nums[end]那么一定sorted，左边最小
        //如果不是，那么有更小的 
        if (nums[start]<nums[end])
          return nums[start];
        //寻找sorted的那一半
        int mid = (start+end)/2;
        if (nums[mid]>=nums[start]) {
          start = mid+1;
        } else {
          end = mid;
        }
      }
      return nums[start];
    }
};
