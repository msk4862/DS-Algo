class Solution {
public:
    // using LIS template
    // O(n^2), O(n) 
    bool canJump_dp(vector<int>& nums) {
        int n = nums.size();
        bool canReach[n+1];
        memset(canReach, 0, sizeof(canReach));
        
        canReach[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                // if I can reach to ith from jth
                if(canReach[j] && i <= nums[j]+j) { 
                    canReach[i] = 1;
                    break;
                }
            }
        }
        
        return canReach[n];
    }
    
    // O(n), O(1)
    bool canJump_greedy(vector<int>& nums) {
        int n = nums.size();
        int maxReach = nums[0];
        
        int i = 1;
        while(maxReach >= i && i < n) {
            maxReach = max(maxReach, nums[i]+i);
            i++;
        }
        return maxReach >= n-1;
    }
    
    bool canJump(vector<int>& nums) {
        return canJump_greedy(nums);
    }
};
