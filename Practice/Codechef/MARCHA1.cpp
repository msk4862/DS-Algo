#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

bool isMoneySubset(int notes[], int n, int money) {
	ll sum = 0;
	
	for(int i = 1; i < pow(2, n); ++i) {
		int ind = 0;
		sum = 0;
		while(ind < n) {
			if(i&(1<<ind)) {
				sum += notes[ind];	
			}
			ind++;
		}
		if(sum == money) return true;
	}
	
	return false;
}


void solve() {   
	int n, m;
	cin>>n>>m;
	
	int notes[n];
	for (int i = 0; i < n; i += 1) {
		cin>>notes[i];
	}
	
	if(isMoneySubset(notes, n, m))
		cout<<"Yes\n";
	else 
		cout<<"No\n";
	
}

int main() {
    FASTIO
    int t;
    cin>>t;
    while(t--) 
    	solve();
    return 0;
}
