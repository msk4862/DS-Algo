#include<bits/stdc++.h>

using namespace std;
#define ll long long int

ll maximum(vector<ll> &a) {
    vector<ll> max_sum(a.size());

    max_sum[0] = a[0];

    for (ll i = 1; i < a.size(); i++)
    {
        max_sum[i] = max(a[i], max_sum[i-1] + a[i]);
    }
    
    return *max_element(max_sum.begin(), max_sum.end());
}


int main() {

    ll t, n;
    cin>>t;
    while(t-- ) {
        cin>>n;
        vector<ll> a;

        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        cout<<maximum(a)<<"\n";
    }
    return 0;
}