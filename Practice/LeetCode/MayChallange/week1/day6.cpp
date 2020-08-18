class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int count = 1, maj=nums[0];
        for(int i = 1; i < n; ++i) {
            if(maj == nums[i]) {
                count++;
                if(count > n/2) return maj;
            }
            else {
                count--;
                if(count == 0) {
                    maj = nums[i];
                    count=1;
                }
                    
            }
        }
        
        
        return maj;
    }
};