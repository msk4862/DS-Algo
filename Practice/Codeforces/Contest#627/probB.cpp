#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int a[], int s, int e) {
	if(e-s==1) 
		return a[s] == a[e];
	if(e-s == 2 )
		return a[s] == a[e];
	
	// if(a[s] == a[e]) return isPalindrome(a, s+1, e-1); 
	return isPalindrome(a, s+1, e) or isPalindrome(a, s, e-1) or isPalindrome(a, s+1, e-1);
	
}

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
		
		
		if(isPalindrome(a, 0, n-1)) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}
