// https://www.geeksforgeeks.org/weighted-job-scheduling/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int dp[100];

// next job postion that does not overlap with current  nth job
int nonOverlappingJob(int jobs[][3], int n) {
	for (int i = n-1; i >= 0; i -= 1) {
		// finish time < start time of nth
		if(jobs[i][1] <= jobs[n-1][0]) return i+1;
	}
	
	return -1;
}

int getMaxProfitTD(int jobs[][3], int n) {
	if(n == 1) return jobs[n-1][2];
	
	if(dp[n-1] != -1) return dp[n-1];
	
	// max profit excluding current job 
	int p1 = getMaxProfitTD(jobs, n-1);

	// including current job	
	int p2 = jobs[n-1][2];

	int nextPossibleJob = nonOverlappingJob(jobs, n);
	if(nextPossibleJob != -1)
		p2 += getMaxProfitTD(jobs, nextPossibleJob);
	
	return dp[n-1] = max(p1, p2);
}

void solve() {   
	int n;
	cin>>n;
	
	
	// start time, end time, profit
	int jobs[n][3];
	for (int i = 0; i < n; i += 1) {
		cin>>jobs[i][0]>>jobs[i][1]>>jobs[i][2];
	}
	
	memset(dp, -1, sizeof(dp));
	cout<<getMaxProfitTD(jobs, n);
}

int main() {
    FASTIO
    solve();
    return 0;
}
