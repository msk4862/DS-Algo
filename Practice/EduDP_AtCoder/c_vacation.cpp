#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll max_happy(ll n) {
    
}


ll get_max_happy_bu(ll n) {
    ll a, b, c;

    ll dp[n][3];

    for (int i = 0; i < n; i++) {
        cin>>a>>b>>c;
        if(i == 0) {
            dp[i][0] = a;
            dp[i][1] = b;
            dp[i][2] = c;
        }
        else {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a;
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b;
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c;
        }
    }

     
    return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
    
}

void solve() {
    ll n;
    cin>>n;

    cout<<get_max_happy_bu(n)<<"\n";
}

int main() {
    FASTIO;
    solve();
    return 0;
}