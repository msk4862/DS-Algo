#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n;
		cin>>n;
		
		int a[n];
		for(int i = 0; i < n; ++i) {
			cin>>a[i];
		}
		
		bool f =1;

		for(int i = 0; i < n-1; ++i) {
			int diff = abs(a[i] - a[i+1]);
			if(diff%2 != 0) {
				f=0;
				break;
			} 		
		}
		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}
