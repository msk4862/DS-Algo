#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll n,t;
    cin>>n>>t;

    ll wheel[t*n];
    for(int i = 0; i < t*n; ++i) {
        cin>>wheel[i];
    }

    ll luckyNum[n];
    for(int i = 0; i < n; ++i) {
        cin>>luckyNum[i];
    }
    
    ll fortune[t];
    for(int i = 0; i < t; ++i) {
        cin>>fortune[i];
    }
    
}

int main() {
    FASTIO
    solve();
    return 0;
}