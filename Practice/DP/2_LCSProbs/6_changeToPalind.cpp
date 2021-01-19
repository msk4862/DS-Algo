// https://www.geeksforgeeks.org/minimum-number-deletions-make-string-palindrome/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


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

int minDelToPalindrome(string s) {
    if(s.size() == 0) return 0;

    // if we just find longest palindromic subsequence present in the string
    // then the rest of the part of the string can be just deleted and it will also be minimum
    // as we are finding longest palindrome subsequence present in the string
    int lps_length =  lps_bu(s);

    return s.size() - lps_length;
}

int main() {
    string s;
    cin>>s;

    cout<<minDelToPalindrome(s)<<"\n";

    return 0;
}