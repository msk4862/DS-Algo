#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    ll c, r;
    cin>>c>>r;

    ll q1 = c/9;
    ll q2 = r/9;


    ll r1 = c%9;
    ll r2 = r%9;

    if(abs(q1-q2) == 1 && ((r1==0 && r2!=0) || (r1!=0 && r2==0))) {
        // if(q1 < q2 && (r2==0 && r1!=0)) {
            cout<<1<<" "<<max(q1, q2)<<"\n";
        // }
        return;
    }

    if(q1 > q2) {
        if(r2==0)
            cout<<1<<" "<<q2<<"\n"; 
        else
            cout<<1<<" "<<q2+1<<"\n";
        return;
    }
    else if(q1 < q2) {
        if(r1 == 0)
            cout<<0<<" "<<q1<<"\n"; 
        else
            cout<<0<<" "<<q1+1<<"\n"; 
        return;
    }

    if(r1 and r2) {
        cout<<1<<" "<<q2+1;
    }
    else {
        if(r1 ==0 and r2 == 0) {
            cout<<1<<" "<<q2;
        }
        else if(r1 ==0) 
            cout<<0<<" "<<q1;
        else 
            cout<<1<<" "<<q2;
    }

    // if(r1 == r2) {
    //     if(r1 ==0) 
    //         cout<<1<<" "<<q2;
    //     else
    //         cout<<1<<" "<<q2+1;
    // } 
    // else if(r1 < r2) {
    //     if(r1 == 0)
    //         cout<<1<<" "<<q1;
    //     else
    //         cout<<1<<" "<<q2+1;
    // } 
    // else {
    //     if(r2 == 0)
    //         cout<<1<<" "<<q2;
    //     else
    //         cout<<1<<" "<<q2+1;
    // }
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