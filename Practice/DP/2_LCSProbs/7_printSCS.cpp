// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string print_lcs_bu(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();

        int dp[n1+1][n2+1];

        for (int i = 0; i <= n1; ++i) {
            for (int j = 0; j <= n2; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string scs = "";

        // moving in reverse order
        int i = n1, j = n2;
        while(i > 0 && j > 0) {
            //common
            // came from diagonal
            if(s1[i-1] == s2[j-1]) {
                scs = s1[i-1] + scs; 
                i--;
                j--;
            }
            
            // came from top
            // skipping ith char of s1
            // as its not part of lcs so include it
            else if(dp[i][j] == dp[i-1][j])  {
                scs = s1[i-1] + scs;
                i--;
            }
            // came from left
            else {
                scs = s2[j-1] + scs;
                j--;
            }
        }
        
        // if any string is yet left
        if(i > 0) scs = s1.substr(0, i) + scs;
        else if(j > 0) scs = s2.substr(0, j) + scs;

        return scs;
    }

    
    string shortestCommonSupersequence(string str1, string str2) {
        return print_lcs_bu(str1, str2);
    }
};