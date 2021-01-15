class Solution {
public:
    
    int lca_td(string s1, string s2, int n1, int n2,int dp[][1001]) {
        if(n1==0 or n2==0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(s1[n1-1] == s2[n2-1]) return dp[n1][n2] =  1 + lca_td(s1, s2, n1-1, n2-1, dp);

        return dp[n1][n2] = max(lca_td(s1, s2, n1-1, n2, dp), lca_td(s1, s2, n1, n2-1, dp));

    }
    
    int lca_bu(string s1, string s2) {
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
    
    // optimised space
    // as we are using only above row
    int lca_bu_opt(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int dp[2][n2+1];

        for (int i = 0; i <= n1; ++i) {
            // dp[i%2][0] = 0;
            for (int j = 0; j <= n2; ++j) {
                if(i == 0 || j == 0) dp[i%2][j] = 0;
                else if(s1[i-1] == s2[j-1]) dp[i%2][j] = dp[(i-1)%2][j-1]+1;
                else dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
            }
        }

        return dp[n1%2][n2];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        // int dp[1001][1001];
        // memset(dp, -1, sizeof(dp)); 
        // return lca_td(text1, text2, text1.size(), text2.size(), dp);   
        
        // return lca_bu(text1, text2);   
        return lca_bu_opt(text1, text2);
    }
};
