#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

vector<string> solve() {
    int n;
    cin>>n;

    vector<string> w(n);
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        cin>>w[i];
        if(w[i][0] != '#')
            flag = 0;
    }

    if(flag)
        return w;
    
    vector<string> res;
    int i;
    for (i = 0; i < n; i++) {
        // w.erase()
        if(w[i][0] != '#') {
            res.insert(res.begin(), w[i]);
            break;
        }
        else {
            res.push_back(w[i]);
        }
    }

    
    // for(string a: res) 
    //     cout<<a<<" ";
    // cout<<"\n";

    // cout<<i<<" ";
    for (int j = n-1; j > i; j--) {
        res.insert(res.begin(), w[j]);
    }

    return res;
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        vector<string> r = solve();

        for(string a: r) 
            cout<<a<<" ";
        cout<<"\n";
    }
    return 0;
}