class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        
        while(l <= h) {
            // mid will lie in 1st sorted arr or 2nd sorted arr
            int mid = (h-l)/2 + l;
            
            if(nums[mid] == target) return mid;
            
            // inside 1st sorted array
            
            // no need to check from 0th index because may be 
            // we have already rejected 0...mid range for any previous mid 
            
            // Also can do with 0 too
            if(nums[l] <= nums[mid]) {
                if(nums[l] <= target and target < nums[mid])
                    h = mid-1;
                else
                    l = mid+1;
            } 
            // 2nd sorted arr
            else {
                if(target >= nums[mid] and target <= nums[h])
                    l = mid+1;
                else
                    h = mid-1;
            }
            
        }
        return -1;
    }
};
