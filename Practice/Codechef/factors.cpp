#include<bits/stdc++.h>

using namespace std;
#define ll long long int

vector<ll> allFactors(ll A) {
        
    vector<ll> a;
    for(ll i = 1; i <= sqrt(A); ++i) {
        if(A%i == 0) {
            if(A/i != i) {
                a.push_back(i);
                a.push_back(A/i);
            } else {
                a.push_back(i);
            }
        }
    }
    
    sort(a.begin(), a.end());
    
    return a;
    
}

int main() {
    ll t, n;
    cin>>t;
    while(t-- ) {
        cin>>n;

        vector<ll> res = allFactors(n);

        for (int i = 0; i < n; i++)
        {
            cout<<res[i];
        }
        cout<<endl;
        
        
    }
}

