// https://www.geeksforgeeks.org/minimum-number-deletions-insertions-transform-one-string-another/

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

int min_oprs(string initial, string target) {

    int lcs_length = lcs(initial, target);

    int min_oprs_required = 0;
    // delete operaions required = initial string - common string subsequence part
    min_oprs_required += initial.size() - lcs_length;

    // insert operaions required = target string - common string subsequence part
    min_oprs_required += target.size() - lcs_length;

    return min_oprs_required; 
}

int main() {

    string initial, target;
    cin>>initial>>target;

    cout<<min_oprs(initial, target);

    return 0;
}