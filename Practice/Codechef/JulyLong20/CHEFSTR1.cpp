#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll solve(vector<ll> st) {
    
    ll skips = 0;
    
    for (int i = 0; i < st.size()-1; i++) {
        skips += abs(st[i]-st[i+1])-1;    
    }

    return skips;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<ll> st(n);

        for (int i = 0; i < n; i++) {
            cin>>st[i];
        }
        cout<<solve(st)<<"\n";
    }
    return 0;
}