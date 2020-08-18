#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll MOD = 1000000007;

ll compute(ll a, ll b, ll c, ll d, ll x1, ll x2) {

    return ((a%d)*(x1%d)%d + (b%d)*(x2%d)%d + c%d)+1;
 }


void solve(int t) {
    ll n, k, wd;
    cin>>n>>k>>wd;

    ll a, b, c, d;

    ll l[n], h[n];
    
    // L
    for (ll i = 0; i < k; i++) {
        cin>>l[i];
    }
    cin>>a>>b>>c>>d;

    for (ll i = k; i < n; i++) {
        l[i] = compute(a, b, c, d, l[i-2], l[i-1]);
    }
    

    // H
    for (ll i = 0; i < k; i++) {
        cin>>h[i];
    }
    cin>>a>>b>>c>>d;

    for (ll i = k; i < n; i++) {
        h[i] = compute(a, b, c, d, h[i-2], h[i-1]);
    }
    

    ll p[n];

    p[0] = (2*((wd%MOD + h[0]%MOD)%MOD))%MOD;

    for (ll i = 1; i < n; i++) {
        if(l[i-1]+wd >= l[i]) {
            if(h[i] >= h[i-1])
                p[i] = ((2*wd)%MOD + (2*h[i])%MOD + (2*((l[i]%MOD)-(l[i-1])%MOD)%MOD)%MOD)%MOD;
            else
                p[i] = ((2*wd)%MOD + (2*h[i-1])%MOD + (2*((l[i]%MOD)-(l[i-1])%MOD)%MOD)%MOD)%MOD;
        }
        else {
            p[i] = (p[i-1] + (2*((wd%MOD + h[i]%MOD)%MOD))%MOD)%MOD;
        }

    }

    ll ans=1;

    for (ll i = 0; i < n; i++) {
        cout<<p[i]<<" ";
        ans = ((ans%MOD)*(p[i]%MOD))%MOD;
    }

    cout<<"Case #"<<t<<": "<<ans<<"\n";

}

int main() {
    FASTIO;
    int t;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}