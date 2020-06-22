#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll maxSequence(ll m, vector<ll> ar) {

    for (int i = 0; i < ar.size(); i++)
    {
        /* code */
    }
    
     
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n, m;
        cin>>n>>m;

        set<ll> a;

        // it will count all the element except m 
        int elements = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin>>x;
            if(x!=m) {
                a.insert(x);
                elements++;
            }
        }
        
        int mex = 1;
        while(a.count(mex)) mex++;

        // if m < original mex then its already not inserted in the set and 'mex' wil be equal to that
        if(m == mex) cout<<elements<<"\n";

        else cout<<"-1\n";

        //OR
        // int mex = 1;
        // while(a.count(mex)) mex++;

        // if(m == mex) return ar.size();
        
        // // need to add elements in ar to hold the condition
        // else if (m > mex) return -1;

        // // m < mex ( 'm' must be present in the set)
        // else return a.size()-1;

    }
    return 0;
}