//https://www.geeksforgeeks.org/edit-distance-dp-5/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int minEditCost_td(string s1, string s2, int n1, int n2, int dp[][101]) {
    if(n1 == 0 && n2 ==0) return 0;
    // cost of inserting n2 chars
    if(n1==0) return n2;
    // cost of deletion of n1 chars
    if(n2==0) return n1;

    if(dp[n1][n2] != -1) return dp[n1][n2];

    if(s1[n1-1] == s2[n2-1]) return dp[n1][n2] = minEditCost_td(s1, s2, n1-1, n2-1, dp);
    // cost = min( cost of deletion, cost of insetion, cost of replace) 
    return dp[n1][n2] = min(minEditCost_td(s1, s2, n1-1, n2, dp), min(minEditCost_td(s1, s2, n1, n2-1, dp), minEditCost_td(s1, s2, n1-1, n2-1, dp))) + 1;
}


int minEditCost_bu(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();

    int dp[n1+1][n2+1];

    for(int i = 0; i <= n1; ++i) {
        for (int j = 0; j <= n2; ++j) {
            if(i == 0 && j == 0) dp[i][j] = 0;
            else if(i == 0 && j != 0) dp[i][j] = j;
            else if(i != 0 && j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }

    return dp[n1][n2];
}

int main() {

    string s1, s2;
    cin>>s1>>s2;

    int n1 = s1.size(), n2 = s2.size();

    /*
    int dp[101][101];
    memset(dp, -1, sizeof(int)*(101)*(101));
    cout<<minEditCost_td(s1, s2, n1, n2, dp)<<"\n";
    */

    cout<<minEditCost_bu(s1, s2)<<endl;
    return 0;
}