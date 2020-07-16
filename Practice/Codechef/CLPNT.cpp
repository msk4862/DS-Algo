#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int searchb(ll walls[], int n, ll val) {
    // int n = walls.size();
    int l = 0, e = n-1, m;

    while(l <= e) {
        m = (e-l)/2 + l;

        if(walls[m] == val)
            return -1;

        else if(walls[m] < val)
            l = m+1;
        else 
            e = m-1;
    }

    return l;

}

ll solve() {
    ll n, q;
    cin>>n;

    ll walls[n];
    for (int i = 0; i < n; i++) {
        cin>>walls[i];
    }

    cin>>q;

    while (q--) {
        ll x,  y;
        cin>>x>>y;

        ll t = x+y;
        cout<<searchb(walls, n, t)<<"\n";
    }
     
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