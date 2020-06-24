#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


int longestSeq(vector<ll> ar, int lis[]) {

    int n = ar.size();

    if(n==0) return 0;

    // single num is itself an longest sequesnce
    // int lis[n] = {1};


    for(int i = 1; i < n; ++i) {
        for (int j = 0; j < i; j++) {
            if(ar[j] < ar[i] ) {
                lis[i] = max(lis[i], 1+lis[j]);
            }
        }
        
    }

    return *max_element(lis, lis+n);
}

int printLongestSeq(vector<ll> ar, int lis[], int n) {

    int maxI = 0;
    for(int i = 0; i < n; ++i) {
        if(lis[maxI] < lis[i]) maxI=i;
    }

    cout<<ar[maxI]<<" ";

    for(int i = maxI-1; i >= 0; --i) {
        if(lis[maxI]-lis[i] == 1) {
            cout<<ar[i]<<" ";
            maxI  = i;
        }
    }

}


int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        vector<ll> ar(n);
        for (int i = 0; i < n; i++) {
            cin>>ar[i];
        }

        int lis[n] = {1};
        cout<<longestSeq(ar, lis)<<"\n";
        printLongestSeq(ar, lis, n);
        
    }
    return 0;
}