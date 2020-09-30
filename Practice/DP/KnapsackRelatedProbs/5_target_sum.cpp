/*
    Probem link: https://leetcode.com/problems/target-sum/
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// pure recursive solution
// int target_sum(int ar[], int sum, int n) {
//     if(n==0 and sum==0)
//         return 1;
//     if(n==0 and sum!=0)
//         return 0;

//     return target_sum(ar, sum-ar[n-1], n-1) + target_sum(ar, sum+ar[n-1], n-1);
    
    
// }


ll count_subsets(ll a[], ll n, ll sum) {

    ll dp[n+1][sum+1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if(a[i-1] <= j)
                dp[i][j] = (dp[i-1][j-a[i-1]] + dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

void solve() {
    ll target, n;
    cin>>target>>n;
    
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    // target = (all plus - all minus) 
    int sum = accumulate(a, a+n, 0);
    ll dif = (sum-target)/2 + target;
    
    // if diff is in decimals
    if((target+sum)%2!=0 or sum < target) cout<<"0";

    cout<<count_subsets(a, n, dif)<<" ";

    
}

int main() {
    FASTIO
    solve();
    cout<<"\n";
    return 0;
}