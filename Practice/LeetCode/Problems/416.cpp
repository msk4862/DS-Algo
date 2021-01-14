class Solution {
public:
    bool is_subset_sum(vector<int> nums, int sum) {
        int n = nums.size();
        
        bool dp[n+1][sum+1];
        
        for(int i = 0; i <= n; ++i) dp[i][0] = 1;
        for(int i = 1; i <= sum; ++i) dp[0][i] = 0;
    
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= sum; ++j) {
                if(j >= nums[i-1]) // 0-indexing in array nums
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        // if sum is odd
        // we can't divide in equal partiations 
        if(sum & 1) return false;
        
        // its now subset sum problem of subset having sum=sum/2
        return is_subset_sum(nums, sum/2);
    }
};
