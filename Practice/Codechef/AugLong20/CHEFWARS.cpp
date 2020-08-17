#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll h, p;
    cin>>h>>p;
    
    bool f = 0;
    while(p > 0) {
        h-=p;
        if (h <= 0) {
            f=1;
            break;
        }
        p/=2;
    }

    if(f) cout<<"1";
    else cout<<"0";
    cout<<"\n";
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