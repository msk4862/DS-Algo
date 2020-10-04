#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll dp[101][100001];

ll max_profit(ll l[], ll price[], ll L, ll n) {
    if(n ==0 or L== 0)
        return 0;

    if(dp[n][L]) return dp[n][L];
    
    if(l[n-1] <= L) {
        // in unbouded knasack we can use one item more than one time also
        return dp[n][L] = max(max_profit(l, price, L-l[n-1], n)+price[n-1], max_profit(l, price, L, n-1));
    }
    else
        return dp[n][L] = max_profit(l, price, L, n-1);
}


ll max_profit_bu(ll l[], ll price[], ll L, ll n) {

    ll dp[n+1][L+1];

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
    ll n, L;
    cin>>n>>L;
    
    ll l[n];
    ll price[n];

    for (int i = 0; i < n; i++) {
        cin>>l[i]>>price[i];
    }

    memset(dp, 0, sizeof(dp[0][0])*101*100001);

    cout<<max_profit(l, price, L, n);   
}

int main() {
    FASTIO;
    solve();
    return 0;
}