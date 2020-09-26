
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll n;

    ll sum=1;
    for (int i = 2; i < sqrt(n); i++) {
        if(n%i == 0)
            sum+= i + (n/i);
    }

    cout<<sum<<"\n";
    
}

int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}