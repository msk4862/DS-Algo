class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int st;
    
        bool dp[n][n];    
        memset(dp, false, sizeof(dp[0][0])*n*n);
        
        // starting from bottom right (visualize filling of dp table)
        // filling left to right
        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                // base cases (str of length 1, 2, 3
                if(j-i < 3 && s[i] == s[j]) {
                    dp[i][j] = true;
                }
                
                else if(s[i] == s[j] && dp[i+1][j-1]) dp[i][j] = true;
            
                
                if(dp[i][j] && maxLen < j-i+1) {
                    st = i;
                    maxLen = j-i+1;                    
                }
                    
            }
        }
        
        return s.substr(st, maxLen);
    }
};
