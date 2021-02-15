#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {   
	ll w, h, n;
	cin>>w>>h>>n;

	ll peices1 = 1, peices2 = 1;
	ll mask = 1;
	while((mask && w) == 0) {
		peices1++;
		mask<<=1;
	}
	mask = 1;
	while((mask && h) == 0) {
		peices2++;
		mask<<=1;
	}

	cout<<peices1<<" "<<peices2<<endl;

	bool res = false;
	if(w&1 == 0 && h&1 == 0) {
		res = peices1*peices2 >= n ? true:false;
	}
	else if(w&1 == 0 || h&1 == 0) {
		res = max(peices1, peices2) >= n ? true:false;
	}

	if(res) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}

int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--) {
	    solve();
    }
    return 0;
}