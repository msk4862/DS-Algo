/*
Divide array in  Subsets having given sum difference. Return such total divisions.
Sum(s1) - Sum(s2) = traget
Sum(s1) + Sum(s2) = Sum(A) 
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);



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
    ll n, diff;
    cin>>n>>diff;

    ll a[n], sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    // sum(s1)-sum(s2) = diff
    // sum(a)-2sum(s2) = diff
    ll target_sum = (sum-diff)/2;
    cout<<count_subsets(a, n, target_sum);
    
}

int main() {
    FASTIO;
    solve();
    return 0;
}