#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    int n;
    cin>>n;

    ll a[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }


    if(n > 63) {cout<<"NO\n"; return;}

    set<ll> ors;
    ll cur;
    bool f =1;
    for (int i = 0; i < n; ++i)
    {
        cur =0;
        for (int j = i; j < n; ++j)
        {
            cur |=a[j];
            if(ors.find(cur) != ors.end()) {
                f = 0;
                break;
            }
            ors.insert(cur);
        }
        
        if(!f) break;
    }
    
    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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