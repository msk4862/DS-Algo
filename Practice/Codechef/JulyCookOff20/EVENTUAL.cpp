#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    int n;
    cin>>n;

    unordered_map<char, int> c;
    char e;
    for (int i = 0; i < n; i++) {
        cin>>e;
        if(c[e])
            c[e]++;
        else
            c[e] =1;
    }
    bool f = 1;
    for(auto e: c) {
        if(e.second%2 != 0) {
            f =0;
            break;
        }
    }
    if(f) cout<<"YES";
    else cout<<"NO";
    cout<<"\n";

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