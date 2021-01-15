/* Given a set of non-negative integers, and a value sum, determine if there is a subset of 
the given set with sum equal to given sum. 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


bool is_subset_sum(ll a[], ll n, ll sum) {

    bool dp[n+1][sum+1];

    // if sum == 0, then its always possible
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    // if sum>0 and a={}, then its not possible
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(a[i-1] <= j)
                dp[i][j] = (dp[i-1][j-a[i-1]] or dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}


ll count_subsets(ll a[], ll n, ll sum) {

    ll dp[n+1][sum+1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
        	if(i == 0 && j == 0) dp[i][j] = 1;
    		// if sum>0 and a={}, then its not possible
        	else if (i == 0 && j != 0) dp[i][j] = 0;
            else if(a[i-1] <= j)
                dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][sum];
}

void solve() {
    ll n, sum;
    cin>>n>>sum;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    // if(is_subset_sum(a, n, sum))
    //     cout<<"Possible\n";
    // else
    //     cout<<"Not Possible\n";

    cout<<count_subsets(a, n, sum);

    
}

int main() {
    FASTIO;
    solve();
    return 0;
}