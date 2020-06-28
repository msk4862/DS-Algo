#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int max_sum(vector<ll> ar, int k) {
    
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<ll> a(n); 
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }

        cout<<max_sum(a, k)<<"\n";

    }
    return 0;
}