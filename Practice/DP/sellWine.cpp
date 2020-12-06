// https://www.geeksforgeeks.org/maximum-profit-sale-wines/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int getMaxProfitTD(int winesPrice[], int n, int start, int end, int dp[][101]) {
   if(start > end)
       return 0;
   
   cout<<start<<" ";
   if(dp[start][end] != -1) return dp[start][end];
   
	int curYear = n - (end-start);

   // profit after selling first bottol
   int p1 = winesPrice[start]*curYear + getMaxProfitTD(winesPrice, n, start+1, end, dp);
   
   // profit after selling last bottol
   int p2 = winesPrice[end]*curYear + getMaxProfitTD(winesPrice, n, start, end-1, dp);
   
   return dp[start][end] = max(p1, p2);
}


int getMaxProfitBU(int winesPrice[], int n) {

	int dp[n][n];

	// start > end -> invalid input
	// don't have to set these
	
	// curyear = n - (start-end)
	// set diagonals values for base case
	for (int i = 0; i < n; i += 1) {
		// last year selling price
		dp[i][i] = winesPrice[i]*n;
	}

	
	// travesring diagonal wise
	for (int i = 0; i < n-1; i += 1) {
		for(int end = i+1, start = 0; end < n; ++start, ++end) {
			int curYear = n - (end-start);
			
			int p1 = winesPrice[start]*curYear + dp[start+1][end];
			int p2 = winesPrice[end]*curYear + dp[start][end-1];
			
			dp[start][end] = max(p1, p2);
		}
	}
	
	return dp[0][n-1];
}

void solve() {   
	int n;
	cin>>n;
	int winesPrice[n];
	for (int i = 0; i < n; i += 1) {
		cin>>winesPrice[i];
	}
	
	int dp[101][101];
	memset(dp, -1, sizeof(dp[0][0])*(101)*(101));
	
	cout<<getMaxProfitTD(winesPrice, n, 0, n-1, dp)<<endl;
	cout<<getMaxProfitBU(winesPrice, n);
	
}

int main() {
    FASTIO
    solve();
    return 0;
}
