#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void inc_dec(vector<ll> ar) {

    sort(ar.begin(), ar.end());

    unordered_map<ll, ll> freq;

    for (int i = 0; i < ar.size(); i++) {   
        if(freq.count(ar[i]) > 0)
            freq[ar[i]]++;
        else
            freq[ar[i]] = 1;
    }

    bool possible=true;

    for(auto x : freq) {
        if(x.second > 2) {
            possible = false;
            break;
        }
    }

    // more than 3 freq or max element has duplicates
    if(!possible or freq[ar[ar.size()-1]] > 1) {
        cout<<"NO\n";    
        return;
    }

    cout<<"YES\n";
    // printing all distinct elements
    for (int i = 0; i < ar.size(); i++) {
        if(freq[ar[i]] == 1) {
            cout<<ar[i]<<" ";
            freq[ar[i]]--;
        }
        else if(freq[ar[i]] == 2) {
            cout<<ar[i]<<" ";
            freq[ar[i]] =-1;
        }

    }
    // printing remaining
    for (int i = ar.size()-1; i >= 0; --i) {
        if(freq[ar[i]] == -1) {
            cout<<ar[i]<<" ";
            freq[ar[i]] = 0;
        }
    }

    cout<<"\n";
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;

        vector<ll> ar(n);
        for (int i = 0; i < n; i++) {
            cin>>ar[i];
        }

        inc_dec(ar);
        
    }
    return 0;
}