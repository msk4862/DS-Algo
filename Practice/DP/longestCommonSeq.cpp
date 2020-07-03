#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int longest(string s1, string s2, int i, int j,int dp[][1000]) {
    if(i==-1 or j==-1) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j]) return dp[i][j] =  1 + longest(s1, s2, i-1, j-1, dp);

    int ans = max(longest(s1, s2, i-1, j, dp), longest(s1, s2, i, j-1, dp));

    return ans = dp[i][j];

}

int main() {
    int t;
    cin>>t;

    string s1, s2;
    while(t--) {
        cin>>s1>>s2;

        int dp[1001][1001];
        memset(dp, -1, sizeof(dp)); 
        cout<<longest(s1, s2, s1.length()-1, s2.length()-1, dp)<<"\n";

    }
    return 0;
}