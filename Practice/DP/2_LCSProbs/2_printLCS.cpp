#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

string print_lca_bu(string s1, string s2) {
	int n1 = s1.size(), n2 = s2.size();

	
    int dp[n1+1][n2+1];

    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string lcs = "";

    // movinf in reverse order
    int i = n1, j = n2;
    while(i > 0 && j > 0) {
    	// came from diagonal
    	if(s1[i-1] == s2[j-1]) {
    		lcs = s1[i-1] + lcs; 
    		i--;
    		j--;
    	}
    	// came from left
    	else if(dp[i][j] == dp[i-1][j])	i--;
    	// came from top
    	else j--;
    }

    return lcs;
}

int main() {

    string s1, s2;
    cin>>s1>>s2;

    cout<<print_lca_bu(s1, s2)<<"\n";

    return 0;
}