#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll travel(vector<ll> h, vector<ll> a, ll b, ll k) {
    if(b == k) {
        return a[b];
    }
    
    if(h[b] <= h[k]) {
        return -1;
    }

    bool possible = true;
    ll taste, i;

    ll step = (b-k)/abs(b-k);
    taste = a[b] + a[k];
    
        i = k+step;
        ll cur = k;
        
        while(i != b) {
            
            if(h[i] >= h[b]) {
                possible =false;
                break;
            }
            if(h[i] > h[cur]) {
                
                taste += a[i];
                cur = i;
            }
            i += step;
        }
    
        if(possible)
            return taste;
        
        return -1;

}


void solve() {
    
    ll n, q;
    cin>>n>>q;

    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin>>h[i];
    }
    
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
    }

    ll taste_s[n][n];

    // precalculating tastiness
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            taste_s[i][j] = travel(h, a, i, j);
        }
    }
    while(q--) {
        ll t;
        cin>>t;
        

        if(t==1) {
            ll b, c;
            cin>>b>>c;
            
            a[b-1] = c;
            continue;
        }
        // travel
        else {
            ll b, k;
            cin>>b>>k;
            b -=1;
            k -=1;

            cout<<taste_s[b][k]<<"\n";
        }
    }

}

int main() {
    FASTIO;
    solve();
    
    return 0;
}