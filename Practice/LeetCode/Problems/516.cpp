class Solution {
public:
    int lps_bu(string s) {
        int n = s.size();

        int dp[n][n];
        memset(dp, 0, sizeof(int)*n*n);

        for (int i = 0; i < n; ++i) dp[i][i] = 1;

        // we need left and bottom value for filling dp[i][j]
        // thats why we start from bottom
        // see filling table
        for (int i = n-1; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1]+2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[0][n-1];
    }

    
    int lcs_bu(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();


        int dp[n1+1][n2+1];

        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n1][n2];
    }

    int longestPalindromeSubseq(string s) {
        // using lcs
        // string rev = s;
        // reverse(rev.begin(), rev.end());
        // return lcs_bu(s, rev);
        
        // 2nd approach
        return lps_bu(s);
    }
};
