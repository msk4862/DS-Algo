class Solution {
public:
    int lcs_bu(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        int dp[n1+1][n2+1];
        
        for(int i = 0; i <= n1; ++i) {
            for(int j = 0; j <= n2; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
    
    // same as min deletion to palind 
    int minInsertions(string s) {
        
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());
        // longest palindrome that is already present
        int longestPalind =  lcs_bu(s1, s);
        
        // needs to insert one occurences of chars left to make it palindrome
        return n - longestPalind;
    }
};
