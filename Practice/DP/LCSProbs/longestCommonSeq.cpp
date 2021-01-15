#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int longest_td(string s1, string s2, int n1, int n2,int dp[][1001]) {
    if(n1==0 or n2==0) return 0;

    if(dp[n1][n2] != -1) return dp[n1][n2];

    if(s1[n1-1] == s2[n2-1]) return dp[n1][n2] =  1 + longest_td(s1, s2, n1-1, n2-1, dp);

    return dp[n1][n2] = max(longest_td(s1, s2, n1-1, n2, dp), longest_td(s1, s2, n1, n2-1, dp));

}



int longest_bu(string s1, string s2) {
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


int main() {
    int t;
    cin>>t;

    string s1, s2;
    while(t--) {
        cin>>s1>>s2;

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp)); 
        cout<<longest(s1, s2, s1.length(), s2.length(), dp)<<"\n";

    }
    return 0;
}