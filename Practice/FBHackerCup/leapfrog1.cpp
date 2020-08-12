#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve(int t) {
    string s;
    cin>>s;
    int nb = 0, nu = 0;
    for(int i = 1; i < s.length(); ++i)
        if(s[i] == 'B')
            nb++;
        else if(s[i] == '.')
            nu++;

    cout<<"Case #"<<t<<": ";
    if(nb >= nu and nu>0)
        cout<<"Y";
    else
        cout<<"N";
    cout<<"\n";
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    for(int i = 1; i <=t; i++) {
        solve(i);
    }
    return 0;
}