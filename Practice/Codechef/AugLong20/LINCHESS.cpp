#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll n, k;
    cin>>n>>k;

    ll ans=-1;
    ll turns = 1000000000;

    for (int i = 0; i < n; i++) {
        ll p;
        cin>>p;
        if(k%p == 0) {
            ll t = k/p;
            if(t < turns) {
                turns = t;
                ans = p;
            }
        }
    }

    cout<<ans<<"\n";
    
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}