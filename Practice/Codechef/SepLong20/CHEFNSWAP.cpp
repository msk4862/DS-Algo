#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll ncr(ll n, ll k) 
{ 
	ll res = 1; 

	if (k > n - k) 
		k = n - k; 

	for (ll i = 0; i < k; ++i) { 
		res *= (n - i); 
		res /= (i + 1); 
	} 

	return res; 
} 

ll bin(ll n, ll half) {
    ll s = 1, e = n;
    
    while(s<=e) {
        ll m = (e-s)/2 + s;

        ll sum = m*(m+1)/2;

        if(sum == half) return m;
        else if(half < sum) e = m-1;
        else s = m+1;
    }

    return s;
}

void solve() {
    ll n;
    cin>>n;

    ll total = n*(n+1)/2;
    if(total%2==1) {cout<<0<<"\n"; return;}
    
    ll half = total/2;
    ll i = bin(n, half);
    
    ll count = 0;
    // cout<<i<<" ";
    
    if(i*(i+1)/2 == half) {
        count += n-i;
        if(i>=2)
        count += ncr(i, 2);
        if(n-i >= 2)
        count += ncr(n-i, 2);
    }
    else {
        count += n-i+1;
    }
    cout<<count<<"\n";
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