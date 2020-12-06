#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


int fiboTD(int n, int dp[]) {
    if(n <= 1) return n;
    
    if(dp[n]) return dp[n];
    
    return dp[n] = fiboTD(n-1, dp) + fiboTD(n-2, dp);
}

int fiboBU(int n) {
	int dp[n+1] = {0};
	dp[0] = 0;
	dp[1] = 1;
		
	for(int i = 2; i <= n; ++i) {
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	return dp[n];
}

void solve() {
	int n;
	cin>>n;
	   
	int dp[n+1] = {0};
	cout<<fiboTD(n, dp);
}

int main() {
    FASTIO
    solve();
    return 0;
}
