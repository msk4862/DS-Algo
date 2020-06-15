#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

ll minMoneyChange(ll n, int t_coins, int coins[], ll dp[]) {
    if(n == 0) {
        return 0;
    }

    if(dp[n] != 0) {
        return dp[n];
    } 

    ll ans = INT_MAX, subprob;
    for (int i = 0; i < t_coins; ++i) {
    	if(n >= coins[i])
    		subprob = minMoneyChange(n-coins[i], t_coins, coins, dp)+1;
    		ans = min(ans, subprob);
    }
    dp[n] = ans;
    return dp[n];

    // for constant 3 no. of coins
    // ll c1, c2, c3;
    // c1 = c2 = c3 = INT_MAX;

    // c1 = minMoneyChange(n-1, dp);
    // if(n >= 3)
    //     c2 = minMoneyChange(n-3, dp);
    // if(n >= 4)
    //     c3 = minMoneyChange(n-4, dp);
    // ll ans = min(min(c1, c2), c3) + 1;
    
}

ll minMoneyChangeBU(ll n) {
    ll dp[n+1] = {0};
    dp[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        ll c1, c2, c3;
        c1 = c2= c3 = INT_MAX;

        c1 = dp[i-1];
        if(i >= 3)
            c2 = dp[i-3];
        if(i>= 4)
            c3 = dp[i-4];
        
        dp[i] = min(min(c1, c2), c3) + 1;
    }

    return dp[n];
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        ll dp[n+1] = {0};
        
        int coins[] = {1, 7, 10};
        int t_coins = sizeof(coins)/sizeof(coins[0]);

        cout<<minMoneyChange(n, t_coins, coins, dp)<<"\n";
        // cout<<minMoneyChangeBU(n)<<"\n";
    }
    return 0;
}