#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


ll power(ll x, ll y)  
{  
    ll res = 1; 
     
    if (x == 0) return 0;
  
    while (y > 0)  
    {  
        // odd
        if (y & 1)  
            res = (res*x);  
  
        y = y>>1;
        x = (x*x);  
    }  
    return res;  
}  


void solve(int k) {
    ll n;
    cin>>n;
    
    ll num[n];
    
    for (int i = 0; i < n; i++) {
        num[i] = power(i+1, k);
    }
    
    ll f1 = 0;
    ll f2 = 0;
    
    vector<ll> me;
    for (int i = n-1; i >=0 ; i--) {
        if(f1 > f2) {
            f2 += num[i];
            me.push_back(i);
        }
        else {
          f1 += num[i];  
        }
    }
    
    cout<<abs(f1-f2)<<"\n";
    
    string res="";
    for (int i = 0; i < n; i++) {
        res+="0";
    }
    
    for(auto e:me) 
        res[e] = '1';
    cout<<res<<endl;

}

int main() {
    FASTIO
    int k;
    cin>>k;
    int t;
    cin>>t;
    while(t--) {
        solve(k);
    }
    return 0;
}