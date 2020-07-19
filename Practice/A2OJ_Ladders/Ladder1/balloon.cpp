#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    int n, x, y;
    cin>>n>>x>>y;

    int color;
    bool e=1, h=1;

    for (int i = 0; i < n; i++) {
        cin>>color;
        if(i == 0 and color == x) {
            e=0;
        }
        if(i == n-1 and color == y) {
            h=0;
        }
    }

    if(e&&h) 
        cout<<"OKAY";
    else if(!e && !h)
        cout<<"BOTH";
    else if(!e && h)
        cout<<"EASY";
    else
        cout<<"HARD";
    cout<<"\n";
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}