#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

int editDistance(string s1, string s2, int i, int j, ll dp[][1000]) {
    if(i == -1) return j+1;
    if(j == -1) return i+1;

    if(dp[i][j] != 0) return dp[i][j];

    if(s1[i] == s2[j]) return editDistance(s1, s2, i-1, j-1, dp);

    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    // insert in s1
    op1 = editDistance(s1, s2, i, j-1, dp);
    //deleting from s1
    op2 = editDistance(s1, s2, i-1, j, dp);
    // replace in s1
    op3 = editDistance(s1, s2, i-1, j-1, dp);

    int ans = min(min(op1, op2),op3) + 1;

    return dp[i][j] = ans;


}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;

        ll dp[1000][1000] = {0};

        cout<<editDistance(s1, s2, s1.length()-1, s2.length()-1, dp)<<"\n";
    }
    return 0;
}