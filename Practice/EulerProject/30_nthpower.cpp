#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll power(ll n, ll p) {
    if(p == 1) return n;

    if(p%2==0)
        return power(n*n, p/2);
    else
        return n*power(n*n, p/2);
}

int main() {
    ll n, p;
    cin>>n>>p;
    if(n == 0) return 0;

    cout<<power(n, p)<<"\n";

    return 0;
}