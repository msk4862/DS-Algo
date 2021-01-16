// https://www.geeksforgeeks.org/shortest-common-supersequence/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int lcs(string s1, string s2) {
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

int shortestSuperSeq(string s1, string s2) {

    int lcs_length = lcs(s1, s2);
    // brute super sequence string will be merge of both strings
    // from it we just remove the common part
    return s1.size() + s2.size() - lcs_length; 
}

int main() {

    string s1, s2;
    cin>>s1>>s2;

    return 0;
}