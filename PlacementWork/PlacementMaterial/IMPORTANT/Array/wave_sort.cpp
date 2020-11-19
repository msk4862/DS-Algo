#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {   
	int n = 6;
	
	int a[n] = {4, 5, 6, 8, 10, 20};
	
	for(int i = 1; i < n; i+=2) {
		if(a[i-1] < a[i]) {
			int t = a[i-1];
			a[i-1] = a[i];
			a[i] = t;
		}
		if(i<n-1 && a[i] > a[i+1]) {
			int t = a[i+1];
			a[i+1] = a[i];
			a[i] = t;
		}
	}
	
	for(int i = 0; i < n; ++i) {
		cout<<a[i]<<" ";
	}
}

int main() {
    FASTIO
    solve();
    return 0;
}
