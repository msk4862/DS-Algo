// https://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/

class Solution {
public:
    int countDistinct_td(string s, string t, int ns, int nt, int dp[][1001]) {
        if(nt == 0) return 1;
        if(ns == 0 && nt != 0) return 0;
        
        if(dp[ns][nt] != -1) return dp[ns][nt];
        
        // either include it in current subsequence or not
        if(s[ns-1] == t[nt-1]) return dp[ns][nt] = countDistinct_td(s, t, ns-1, nt-1, dp) + countDistinct_td(s, t, ns-1, nt, dp);
        
        return dp[ns][nt] = countDistinct_td(s, t, ns-1, nt, dp);
    }
    
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        
        int dp[1001][1001];
        memset(dp, -1, sizeof(int)*1001*1001);
        return countDistinct_td(s, t, n1, n2, dp);
    }
};