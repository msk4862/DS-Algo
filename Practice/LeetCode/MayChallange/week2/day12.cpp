class Solution {
public:
    int get(vector<int> nums, int i) {
        if(i>=0 and i<nums.size()) return nums[i];
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size()-1;
        
        while(s<=e) {
            int m = (e-s)/2 + s;
            if(nums[m] != get(nums, m-1) and nums[m] != get(nums, m+1)) {
                return nums[m];
            }
            else if(m%2 == 0) {
                if(nums[m] == get(nums, m+1)) {
                    s=m+1;
                }
                else {
                    e=m-1;
                }
            }
            else {
               if(nums[m] == get(nums, m-1)) {
                    s=m+1;
                }
                else {
                    e=m-1;
                } 
            }
            
        }
        
        return nums[s];
    }
};