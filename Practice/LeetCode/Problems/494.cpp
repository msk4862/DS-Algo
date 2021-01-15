class Solution {
public:
    // brute force recursive approach
    int target_td(vector<int>& nums, int n, int S) {
        if(n == 0 && S == 0) return 1;
        if(n == 0 && S != 0) return 0;
        
        return target_td(nums, n-1, S-nums[n-1]) + target_td(nums, n-1, S+nums[n-1]);
    }

    
    int count_subsets(vector<int>& nums, int S) {
        int n = nums.size();
        int dp[n+1][S+1];
    
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= S; ++j) {
                if(i == 0 && j == 0) dp[i][j] = 1;
        		// if sum>0 and a={}, then its not possible
            	else if (i == 0 && j != 0) dp[i][j] = 0;
                else if(j >= nums[i-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][S];
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        long sum = accumulate(nums.begin(), nums.end(), 0);
        
        int subset_sum = (sum - S)/2 + S;
        
        // edge cases
        if(S > sum || long(sum + S) & 1) return 0;
        return count_subsets(nums, subset_sum);
    }
};
