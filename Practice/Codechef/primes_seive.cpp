#include<bits/stdc++.h>

using namespace std;
#define ll long long int

vector<ll> allPrimes(ll A) {
        
    vector<ll> ar(A+1);
    for (ll i = 0; i <= A; i++)
    {
        ar[i] = i;
    }
    ar[1] = 0;
    
    for (ll i = 2; i <= A; i++)
    {
        if(ar[i] == 0)
            continue;
        for (int j = 2;i*j <= A; j++)
        {
            ar[i*j] = 0;
        }
        
    }
    
    
vector<ll> res;
    
    for (int i = 0; i < ar.size(); i++)
        {   
            if(ar[i] != 0)
                res.push_back(ar[i]);
        }
    
    return res;
        
}

int main() {
    ll t, n;
    cin>>t;
    while(t-- ) {
        cin>>n;

        vector<ll> res = allPrimes(n);

        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i];
        }
        cout<<endl;
        
        
    }
}

