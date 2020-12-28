#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {   
	int n;
	cin>>n;
	string s, p;
	cin>>s>>p;
	
	if(s == p) {
	    cout<<"Yes\n";
	    return;
	}
	
	int ones = 0, zeroes = 0;
	
	for(int i = 0; i < n; ++i) {
	    if(s[i] != p[i])
	        if(s[i] == '0') zeroes++;
	        else ones++;
	}
	
	// number of mismatches are not same
	if(ones != zeroes) {
	    cout<<"No\n";
	    return;
	}
	
	int pre_ones = 0;
	bool ans = true;
	
	for(int i = 0; i < n; ++i) {
        if(s[i]!=p[i]) {
            if(s[i] == '1') pre_ones++;
            // there are ones 1 needs to change to 0 
            // before current 0
            else {
                if(pre_ones > 0)
                    pre_ones--;
                else {
                    ans = false;
                    break;
                }
            }
        }
	}
	
	if(ans) cout<<"Yes\n";
	else cout<<"No\n";
		
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
