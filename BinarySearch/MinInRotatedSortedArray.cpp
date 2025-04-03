class Solution {
public:
    int findMin(vector<int>& nums) {
      int n = nums.size();
      int lo = 0;
      int hi = n-1;
       //if search space is already sorted then the first element is the minimum element
       if(nums[hi]>nums[lo]) return nums[lo];

      while(lo<hi){
        int mid = lo + (hi - lo) /2;
        if(nums[mid+1]<nums[mid]) return nums[mid+1];
        if(nums[lo]<=nums[mid]){
            //in the left part --> go to the right part
            lo = mid + 1;
        }else{
            //otherwise eliminate the left part
            hi = mid;//instead of doing hi = mid -1 as it could possibly lead to the skipping of the required ans
        }
      }
      return nums[lo];
    }
};
