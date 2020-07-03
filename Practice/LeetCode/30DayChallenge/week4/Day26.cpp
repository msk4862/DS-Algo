/*
  Longest Common Subsequence

*/

class Solution {
public:

    int lcs(string s1, string s2, int i, int j, int dp[][1001]) {
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1+ lcs(s1, s2, i-1, j-1, dp);
        
        dp[i][j] = max(lcs(s1, s2, i-1, j, dp), lcs(s1, s2, i, j-1, dp));
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++) {
            for(int j=0;j<n+1;j++) {
                if(i==0||j==0) {
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }

};