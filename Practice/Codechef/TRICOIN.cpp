#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


ll coinsNeeded(ll height) {
    ll m;
    if(height&1) {
        m = (height+1)/2;
        return height*m;
    }
    
    m = height/2;
	return m*(height+1);
}

ll binSearch(ll coins) {
	ll s = 1, l = coins;
	
	ll ans;
	while(s <= l) {
		ll mid = (l-s)/2 + s;
        
        ll coinsForMid = coinsNeeded(mid);
		if(coinsForMid == coins) return mid;
		else if(coinsForMid < coins) { 
		    ans = mid;
		    s = mid+1;
		}
		else l = mid-1;
		    
	}	
	
	return ans;
}

ll linSearch(ll coins) {
    
    ll coinsNeeded = 1;
    ll rows = 0;
    
    while(coins - coinsNeeded >= 0) {
        coins -= coinsNeeded;
        rows++;
        coinsNeeded++;
    }
    cout<<coinsNeeded<<" ";
    return rows;
}

void solve() {   
	ll coins;
	cin>>coins;
	
    cout<<binSearch(coins)<<endl;
    
}

int main() {
    FASTIO
	int t;
	cin>>t;
	while(t--) 
    	solve();
    return 0;
}
