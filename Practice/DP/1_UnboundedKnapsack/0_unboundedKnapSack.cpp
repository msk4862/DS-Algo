#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll dp[101][100001];

ll max_profit(ll w[], ll v[], ll W, ll n) {
    if(n ==0 or W== 0)
        return 0;

    if(dp[n][W]) return dp[n][W];
    
    if(w[n-1] <= W) {
        // if we have included the item -> even then we can take it again 
        return dp[n][W] = max(max_profit(w, v, W-w[n-1], n)+v[n-1], max_profit(w, v, W, n-1));
    }
    else
        return dp[n][W] = max_profit(w, v, W, n-1);
}


ll max_profit_bu(ll w[], ll v[], ll W, ll n) {

    ll dp[n+1][W+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if( i == 0 or j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(w[i-1] <= j)
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
        
    }

    return dp[n][W];
    
}

void solve() {
    ll n, W;
    cin>>n>>W;
    
    ll w[n];
    ll v[n];

    for (int i = 0; i < n; i++) {
        cin>>w[i]>>v[i];
    }

    memset(dp, 0, sizeof(dp[0][0])*101*100001);

    cout<<max_profit(w, v, W, n);   
}

int main() {
    FASTIO;
    solve();
    return 0;
}