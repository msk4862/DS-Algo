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
    bool flag = true;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin>>ar[i];
        if(ar[i] %2 ==0) {
            flag = false;
        }
    }

    

    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<"\n";
    return;
    
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}