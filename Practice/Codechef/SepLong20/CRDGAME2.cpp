#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll MOD = 1000000007;

ll power(ll x, ll y)  
{  
    ll res = 1; 
  
    x = x % MOD;
   
    if (x == 0) return 0;
  
    while (y > 0)  
    {  
        // odd
        if (y & 1)  
            res = (res*x) % MOD;  
  
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res % MOD;  
}  


ll ncr(ll n, ll k) 
{ 
    ll res = 1; 
    
    if (k > n - k) 
        k = n - k; 

    for (ll i = 0; i < k; ++i) { 
        res = ((res% MOD)*((n - i)% MOD)) % MOD; 
        
        res = ((res%MOD)*(power((i+1),MOD-2)%MOD))%MOD;
        // res /= (i + 1); 
    } 

    return res % MOD; 
} 

void solve() {
    ll n;
    cin>>n;

    ll c[n], max_e = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin>>c[i];
        if(max_e < c[i]) max_e = c[i];
    }

    ll max_freq = 0;
    for (int i = 0; i < n; i++) {
        if(c[i] == max_e) max_freq++;
    }

    if(max_freq%2==1) {
        cout<<power(2, n)<<"\n";
        return;
    }

    // even freq
    ll res = power(2, n);
    res -= ((power(2, n-max_freq)%MOD)*(ncr(max_freq, max_freq/2)%MOD))%MOD;

     if(res<0)
        res=(res+MOD)%MOD;

    cout<<res%MOD<<"\n";    
    
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