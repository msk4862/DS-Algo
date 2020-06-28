#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll findMinCoins(ll s, ll n) {
    if(s <= n) {
        if (s == 1) 
            return 1;
        if(s%2 == 0)
            return 1;
        else
            return 2;
    } 
    else {
       ll ans = s/n;
       s%=n;
    // less than n is remaining
       
       if(s==0)
            return ans;
        if (s==1)
            return ans+1;
            
        // similar to 2nd case in s<=n case above
       if(s%2==0)
            return ans+1;
            
        // similar to 3rd case in s<=n case above
        ans+=2;
        return ans;
    }
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        ll s, n;
        cin>>s>>n;

        cout<<findMinCoins(s, n)<<"\n";
    }
    return 0;
}