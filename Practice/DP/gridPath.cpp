#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll maxpath(vector<vector<ll>> grid, int i, int j, vector<vector<ll>> dp) {
    
    if (i < 0 and j < 0) {
        return 0;
    }

    if(dp[i][j]!= 0)
        return dp[i][j];

    dp[i][j] = max(maxpath(grid, i-1, j, dp), maxpath(grid, i, j-1, dp)) + grid[i][j];

    return dp[i][j];
    
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<vector<ll>> grid(n, vector<ll> (n));
        vector<vector<ll>> dp(n, vector<ll> (n, 0));
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>grid[i][j];
            }
        }

        cout<<maxpath(grid, n-1, n-1, dp);
        cout<<"\n";
    }
    return 0;
}