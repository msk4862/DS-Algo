// https://www.codechef.com/CCCLS001/problems/PRPR5

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

bool isDesiredDist(ll freeComp[], int n, ll s, ll dist) {
	ll prevStoneComp = freeComp[0];
	ll stones = 1;
	
	for(int i = 1; i < n; ++i) {
		if(freeComp[i] - prevStoneComp >= dist) {
			stones++;
			prevStoneComp = freeComp[i];
		}
		if(stones == s) return true;
	}
	
	return false;
}

ll binSearch(ll freeComp[], int n, ll s) {
	// min dist = 0, max_dist = first and last compartment
	ll l = 0, h = freeComp[n-1]-freeComp[0];
	
	ll maxMinDist;
	
	while(l <= h) {
		ll mid = (h-l)/2 + l;
		
		// can maximise more max dist
		if(isDesiredDist(freeComp, n, s, mid)) {
			maxMinDist = mid;
			l = mid+1;
		}
		// unable to accomodate all stones
		// decrease max dist
		else {
			h = mid-1;
		}
	}
	
	return maxMinDist;
	
}


void solve() {   
	ll n, s;
	cin>>n>>s;
	
	ll freeComp[n];
	for (int i = 0; i < n; i += 1) {
		cin>>freeComp[i];
	}
	
	sort(freeComp, freeComp + n);
	
	cout<<binSearch(freeComp, n, s)<<endl;	
	
}

int main() {
    FASTIO
    solve();
    return 0;
}
