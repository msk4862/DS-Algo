#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
// #define FASTIO \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(nullptr); \
//     cout.tie(nullptr); \

int minOprTD(ll n, int dp[]) {
    //  Base case
    if(n<=1) {
        return 0;
    } 

    // lookup if dp[n] is already calculated
    if(dp[n] != 0) {
        return dp[n];
    }

    //rec case (if dp[n] is not known)
    int m1, m2=INT_MAX, m3=INT_MAX;
    m1 = minOprTD(n-1, dp);
    if(n%2==0) {
        m2 = minOprTD(n/2, dp);
    }
    if(n%3==0) {
        m3 = minOprTD(n/3, dp);
    }
    
    int ans = min(min(m1, m2), m3) +1;
    dp[n] = ans;
    return dp[n];
}

int minOprBU(ll n) {
    int dp[n];

    dp[1] = 0;
    
    for (int i = 2; i <= n; i++)
    {   
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        op1 = dp[i-1];
        if(i%2==0) {
            op2 = dp[i/2];
        }
        if(i%3==0) {
            op3 = dp[i/3];
        }
        dp[i] = min(min(op1, op2), op3) +1;
    }

    return dp[n];
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        int dp[n] = {0};
        cout<<minOprTD(n, dp);
    }

    return 0;
}