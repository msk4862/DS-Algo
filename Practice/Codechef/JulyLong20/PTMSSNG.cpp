#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve(int n) {
    ll px, py;

    set<ll> x, y;

    // every x and y will come twice in a same rectangle
    for (int i = 0; i < (4*n-1); i++) {
        cin>>px>>py;

        if(x.count(px) > 0) x.erase(px);
        else x.insert(px);
        
        if(y.count(py) > 0) y.erase(py);
        else y.insert(py);
        
    }

    // only missing pair point will remain in the set
    cout<<*x.begin()<<" "<<*y.begin();
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;        
        
        solve(n);
        cout<<"\n";
    }
    return 0;
}