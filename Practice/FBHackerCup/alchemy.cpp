#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve(int t) {
    int n;
    cin>>n;

    string s;
    cin>>s;
    int na = count(s.begin(), s.end(), 'A');
    int nb = count(s.begin(), s.end(), 'B');

    cout<<"Case #"<<t<<": ";
    if(abs(na -nb) > 1)
        cout<<"N";
    else
        cout<<"Y";

    cout<<"\n";
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    for(int i =1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}