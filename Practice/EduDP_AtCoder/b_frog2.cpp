#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll dp[100001];

ll min_cost_bu(ll h[], int n, int k) {
    
    dp[0] = 0;
    // dp[1] = abs(h[1]-h[0]);
    for (int i = 1; i < n; i++) {
        ll cost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if(i-j>=0)
                cost = min(cost, abs(h[i] - h[i-j]) + dp[i-j]);
        }

        dp[i] = cost;
    }

    // for (int i = 0; i < n; i++) {
    //     cout<<dp[i]<<" ";
    // }
    return dp[n-1];
}

void solve() {
    ll n, k;
    cin>>n>>k;
    
    ll h[n];
    for (int i = 0; i < n; i++) {
        cin>>h[i];
    }

    // dp = {0};
    memset(dp, 0, sizeof(dp[0])*100001);

    cout<<min_cost_bu(h, n, k)<<"\n";
    
}

int main() {
    FASTIO;
    solve();
    return 0;
}