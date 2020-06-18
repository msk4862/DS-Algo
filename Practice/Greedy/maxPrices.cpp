#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

vector<ll> maxPrices(ll n) {
    vector<ll> prices;
    ll remPrice = n;
    ll curPrice = 1;

    // only if we have price to offer greater than current price for next price
    while(remPrice > 2*curPrice) {
      prices.push_back(curPrice);
      remPrice-=curPrice;
      curPrice++;
    }

    if(remPrice > 0) {
      prices.push_back(remPrice);
    }

    return prices;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        vector<ll> p = maxPrices(n);

        cout<<p.size()<<"\n";
        for(auto e: p) cout<<e<<" ";
        cout<<"\n";
    }
    return 0;
}