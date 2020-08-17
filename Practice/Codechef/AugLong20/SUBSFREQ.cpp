#include<bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
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
        if (y & 1)  
            res = (res*x) % MOD;  
  
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res;  
}  


// ll power(ll n, ll p) {

//     if(p==0)
//         return 1;

//     if(p%2==0)
//         return power((n%MOD)*(n%MOD)%MOD, p/2);
//     else
//         return ((n%MOD)*power((n%MOD)*(n%MOD)%MOD, p/2)%MOD);
// }


void solve() {
    ll n;
    cin>>n;
    ll num[n];

    for (int i = 0; i < n; i++) {
        cin>>num[i];
    }


    // ll c = 
    // cout<<c<<" ";

    for (int i = 1; i <= n; i++) {
        cout<<power(2, n-i);<<" ";
        // c=c>>1;
    }
    cout<<"\n";

    // for (int i = 1; i < pow(2, n); i++) {
    //     ll count[n+1] = {0};
    //     ll m = 1;
    //     for (int j = 0; j<=i && j < n; j++) {
    //         if((m<<j)&i) {
    //             // cout<<j<<" ";
    //             count[num[j]] = (count[num[j]]+1)%MOD;
    //         }

    //     }

    //     // for (int k = 1; k <= n; k++) {
    //     //     cout<<count[k]<<" ";
    //     // }
    //     // cout<<"\n";
    //     ll pos = distance(count, max_element(count, count+n+1));        
    //     t_count[pos]= (t_count[pos]+1)%MOD;
    // }

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