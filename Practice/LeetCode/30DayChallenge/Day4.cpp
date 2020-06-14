class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zero = 0;
        for(int  i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                int t = nums[i];
                nums[non_zero] = t;
                // nums[i] = 0;
                
                non_zero++;
            }
        }
        
        for(int  i = non_zero; i < nums.size(); ++i) {
            nums[i] = 0;
        }
        
    }
};