#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


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


// brute recusrsive approach
int lps_rec(string s, int start, int end) {
    if(start == end) return 1;
    if(start > end) return 0;

    if(s[start-1] == s[end-1]) 
        return lps_rec(s, start+1, end-1)+2;
    else  
        return max(lps_rec(s, start+1, end), lps_rec(s, start, end-1));
}

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

int longestPalindSeq(string s) {
    if(s.size() == 0) return 0;

    // 1st approach - Using LCS

    // we match palindrome by checking starting chars with ending chars
    // longest palindromic subsequence will just be lcs of string and its reverse (for finding palindrome) 

    // string rev = s;
    // reverse(rev.begin(), rev.end());
    // return lcs_bu(s, rev);


    // 2nd approach - without using LCS (similar intution though)
    return lps_bu(s);
}

int main() {
    string s;
    cin>>s;

    cout<<longestPalindSeq(s)<<"\n";

    return 0;
}