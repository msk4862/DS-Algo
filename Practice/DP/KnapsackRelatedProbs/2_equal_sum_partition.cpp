#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// same as subset sum problem
bool is_subset_sum(ll a[], ll sum, ll n) {
    bool dp[n+1][sum+1];

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

    return dp[n][sum];
    
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
    
    if(sum%2) {
        cout<<"Not possible\n";
    }
    else {
        if(is_subset_sum(a, sum/2, n)) cout<<"Possible\n";
        else cout<<"Not Possible";
    }
}

int main() {
    FASTIO;
    solve();
    return 0;
}