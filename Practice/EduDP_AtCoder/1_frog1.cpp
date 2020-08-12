#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll dp[100001];

ll min_cost(ll h[], int index, int n) {
    if(index >= n-1) {
        return 0;
    }

    if(dp[index]) return dp[index];

    ll cost1, cost2;
    cost1 = cost2 = INT_MAX;

    
    if(index+1 < n)
        cost1 = min_cost(h, index+1, n)+abs(h[index]-h[index+1]);
    if(index+2 < n)
        cost2 = min_cost(h, index+2, n)+abs(h[index]-h[index+2]);
    
    return dp[index] = min(cost1, cost2);
}

ll min_cost_bu(ll h[], int n) {
    
    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(abs(h[i] - h[i-1]) + dp[i-1], abs(h[i] - h[i-2]) + dp[i-2]);
    }

    // for (int i = 0; i < n; i++) {
    //     cout<<dp[i]<<" ";
    // }
    return dp[n-1];
}

void solve() {
    ll n;
    cin>>n;
    
    ll h[n];
    for (int i = 0; i < n; i++) {
        cin>>h[i];
    }

    // dp = {0};
    memset(dp, 0, sizeof(dp[0])*100001);

    cout<<min_cost_bu(h, n)<<"\n";
    
}

int main() {
    FASTIO;
    solve();
    return 0;
}