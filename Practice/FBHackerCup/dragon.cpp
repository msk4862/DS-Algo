#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll n,r;
    cin>>n>>r;

    ll d[n];
    for(int i = 0; i < n; ++i) {
        cin>>d[i];
    }

    sort(d, d+n);
    if(d[n-1] <= 0) cout<<0;

    ll blows = 0;
    for(int i = n-1; i >= 0; --i) {
        if(d[i] - r*(blows) >= 0) {
            if(i > 0 && d[i] != d[i-1])
                blows++;
            else if(i > 0 && d[i] == d[i-1])
                i--;
        }
        else {
            break;
        }
    }

    cout<<blows;
}

int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--) {
        solve();
        cout<<"\n";
    }
    return 0;
}