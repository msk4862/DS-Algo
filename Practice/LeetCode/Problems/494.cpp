class Solution {
public:
    
int count_subsets(vector<int> a, int n, int sum) {

        int dp[n+1][sum+1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = 0;
        }
    
        // for sum=0 and zero elemnts present
        for (int i = 1; i <= n; i++) {
            if(a[i-1] == 0) {
                // empty subset + zero element subset 
                dp[i][0] = 2*dp[i-1][0];
            }    
            else 
                dp[i][0] = dp[i-1][0];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                
                if(a[i-1] <= j)
                    dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];

            }
        }
    

        return dp[n][sum];
    }

    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        
        // target = (all plus - all minus) 
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int dif = (sum-S)/2 + S;
        
        long s= (long)S+sum;
        
        // if diff is in decimals
        if(s%2!=0 or sum < S) return 0;
        return count_subsets(nums, n, dif);
    }
};