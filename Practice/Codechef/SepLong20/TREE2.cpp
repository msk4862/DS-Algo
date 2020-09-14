#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll n;
    cin>>n;

    ll a;
    set<ll> nums;
    for (int i = 0; i < n; i++) {
        cin>>a;
        if(a != 0)
        nums.insert(a);
    }

    cout<<nums.size()<<"\n";
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