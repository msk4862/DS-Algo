/*
      Search in Rotated Sorted Array
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int l = nums.size()-1;
        
        while(s <= l) {
                    // mid will lie in 1st sorted arr or 2nd sorted arr
            int mid = (s-l)/2 + l;
            
            if(nums[mid] == target) return mid;
            
            // inside 1st sorted array
            if(nums[s] <= nums[mid]) {
                if(target >= nums[s] and target <= nums[mid])
                    l = mid-1;
                else
                    s = mid+1;
            } 
            // 2nd sorted arr
            else {
                if(target >= nums[mid] and target <= nums[l])
                    s = mid+1;
                else
                    l = mid-1;
            }
            
        }
        return -1;
    }
};