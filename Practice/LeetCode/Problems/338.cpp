class Solution {
public:
    vector<int> solve1(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i&(i-1)] + 1;
        }
        
        return dp;
    }
    
    vector<int> countBits(int num) {
        return solve1(num);
    }
};
