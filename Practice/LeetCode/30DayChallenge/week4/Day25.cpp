/*
  Jump Game
*/


class Solution {
public:
    // all possible paths
    // slow
    bool canJumpRec(vector<int>& nums, int i, bool dp[]) {
        // cout<<i<<endl;
        if(i >= nums.size()) return dp[i] = false;
        
        if(i == nums.size()-1) return dp[i]= true;
        
        for(int j = nums[i]; j > 0; --j) {
            if(canJumpRec(nums, i+j, dp)) return dp[i] = true; 
        }
        
        return dp[i] = false;
    }
    
    
    
    bool canJump(vector<int>& nums) {
       
    //  bool dp[100000];
    // memset(dp, -1, sizeof(dp));
    //     return canJumpRec(nums, 0, dp);
        
        int reachable = 0;
        for(int i = 0; i < nums.size(); ++i) {
            // cur pos is not reachable only
            if(i > reachable) return false;
            // finding max reachable pos
            reachable = max(nums[i]+i, reachable);
        }
        return true;
    }
};