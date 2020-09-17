class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum = nums[0], step = nums[0];
        
        for(int i = 1; i < nums.size(); ++i) {
            sum+=nums[i];
            step = min(step, sum);
        }
        
        if(step >= 1) return 1;
        
        return abs(step)+1;
    }
};