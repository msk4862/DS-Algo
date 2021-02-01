// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int longest_bu(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    
    int dp[n1+1][n2+1];
    int longest = INT_MIN;
    for (int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            // contnuity broken
            // start again
            else dp[i][j] = 0;
            
            longest = max(longest, dp[i][j]);
        }
    }

    return longest;
}


int main() {

    string s1, s2;
    cin>>s1>>s2;
    cout<<longest_bu(s1, s2)<<"\n";

    return 0;
}