#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


ll max_profit(ll w[], ll v[], ll W, ll n) {
    if(n ==0 or W== 0)
        return 0;

    if(dp[n][W]) return dp[n][W];
    
    if(w[n-1] <= W) {
        return dp[n][W] = max(max_profit(w, v, W-w[n-1], n-1)+v[n-1], max_profit(w, v, W, n-1));
    }
    else
        return dp[n][W] = max_profit(w, v, W, n-1);
}



void solve() {
    ll n, W;
    cin>>n>>W;
    
    ll w[n];
    ll v[n];

    for (int i = 0; i < n; i++) {
        cin>>w[i]>>v[i];
    }

    cout<<max_profit(w, v, W, n);   
}

int main() {
    FASTIO;
    solve();
    return 0;
}