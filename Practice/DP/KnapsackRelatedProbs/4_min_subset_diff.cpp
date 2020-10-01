#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// same as subset sum problem
void is_subset_sum(ll a[], ll sum, ll n, bool dp[][10000]) {

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(a[i-1] <= j) {
                dp[i][j] = dp[i-1][j-a[i-1]] or dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
        
    }
    
}

ll min_subset_diff(ll a[], ll sum, ll n) {
    bool dp[n+1][10000];

    is_subset_sum(a, sum, n, dp);

    ll min_sum = INT_MAX;
    // checking last row (which have result of including all array elem)
    for (int i = 1; i <= sum/2; i++) {
        if(dp[n][i]) {
            min_sum = min(abs(sum-2*i), min_sum);
        }
    }
    
    return min_sum;

}


void solve() {
    ll n;
    cin>>n;

    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        sum+=a[i];
    }
    
    cout<<min_subset_diff(a, sum, n);

}

int main() {
    FASTIO;
    solve();
    return 0;
}