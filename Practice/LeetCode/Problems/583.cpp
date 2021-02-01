class Solution {
public:
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

    int minDistance(string word1, string word2) {
        int lcs_length = lcs_bu(word1, word2);
        return (word1.size() - lcs_length) + (word2.size() - lcs_length);
    }
};
