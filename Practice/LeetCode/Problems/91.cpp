class Solution {
public:
    int countWays_td(string s, int n, int dp[]){
        if(n == 0) return 1; 
        if(n == 1) return s[n-1] != '0'? 1 : 0;
        
        if(dp[n] != -1) return dp[n];
        
        dp[n] = 0;
        // taking single char for decoding
        if(s[n-1] != '0') dp[n] += countWays_td(s, n-1, dp);
        // taking double char for decoding
        if(s[n-2] == '1' || (s[n-2] == '2' && s[n-1] <= '6')) dp[n] += countWays_td(s, n-2, dp);
        
        return dp[n];
    }
    
    int numDecodings(string s) {
        int n = s.size(); 
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return countWays_td(s, s.size(), dp);
    }
};
