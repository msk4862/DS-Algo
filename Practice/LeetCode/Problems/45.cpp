class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int jumps = 0;
        int curEnd = 0;
        int reachable = 0;
        
        for(int i = 0; i < n-1; ++i) {
            // if there is any longer jump (skipped) b/w i...curEnd 
            reachable = max(reachable, nums[i]+i); 
            
            // after we've reached at the cur range(curEnd) end then 
            // we will make the next maxJump that we've found till curEnd
            if(i == curEnd) {
                jumps++;
                curEnd = reachable;
            }
        }
        
        return jumps;
    }
    
};
