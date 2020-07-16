#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll solve() {
    ll n;
    cin>>n;

    ll e;
    unordered_map<ll, int> a, b, total_c, change;

    for(ll i = 0; i < n; ++i) {
        cin>>e;

        if(total_c.count(e))
            total_c[e]++;
        else
            total_c[e] =1;

        if(a.count(e))
            a[e]++;
        else
            a[e] = 1;
    }

    for(ll i = 0; i < n; ++i) {
        cin>>e;
        if(total_c.count(e))
            total_c[e]++;
        else
            total_c[e] =1;

        if(b.count(e))
            b[e]++;
        else
            b[e] = 1;
    }

    for(auto x: total_c) {
        if((x.second%2)==1)
            return -1;
    }

    // possible
    for(auto x: total_c) {

        if(a[x.first] != b[x.first]) 
            change[x.first] = abs(a[x.first] - b[x.first])/2;
    }

    // already identical
    if(change.size()==0) return 0;

    vector<ll> arr;
    for(auto x: change) {
        // required swapping elements array
        for (ll i = 0; i < x.second; i++) {
            arr.push_back(x.first);
        }
    }

    sort(arr.begin(), arr.end());

    ll cost = 0;
    ll min_e = (*min_element(total_c.begin(), total_c.end())).first;
    for (ll i = 0; i < arr.size()/2; i++) {   
        // if one swap of arr[i] cost greater than 2 swaps with minimum element
        if(arr[i] > 2*min_e)
            cost += 2*min_e;
        else
            cost += arr[i];
    }

    return cost;
    
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        cout<<solve()<<"\n";
    }
    return 0;
}