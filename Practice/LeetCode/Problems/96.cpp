class Solution {
public:
    int numTreesTD(int n, vector<int>& dp) {
        if(n == 0 || n==1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int total = 0;
        for(int i = 1; i <= n; ++i) {
            total += numTreesTD(i-1, dp)*numTreesTD(n-i, dp);
        }
        
        return dp[n] = total;
    }
    
    int numTreesBU(int n) {
        int dp[n+1];
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= n; ++i) {
            dp[i] = 0;
            for(int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1]*dp[i-j];
            } 
        }
        
        return dp[n];
    }
    
    int numTrees(int n) {
        
        // vector<int> dp(n+1, -1);
        // return numTreesTD(n, dp);
        
        return numTreesBU(n);
    }
};
