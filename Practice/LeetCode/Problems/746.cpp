class Solution {
public:
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n];
        memset(dp, 0, sizeof(int)*n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; ++i) {
            dp[i] = min(dp[i-1], dp[i-2])+cost[i];
        }
        for(int i=0; i<n; ++i) {
            cout<<dp[i]<<" ";
        }
        return min(dp[n-2],dp[n-1]);
    }
};