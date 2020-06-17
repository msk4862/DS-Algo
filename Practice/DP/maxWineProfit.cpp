#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr); \

int maxWineProfit(int prices[], int start, int last, int year, int dp[][100]) {

    if(start > last) {
        return 0;
    }

    if(dp[start][last] != 0) {
        return dp[start][last];
    }

    int ans = max(prices[start]*year + maxWineProfit(prices, start+1, last, year+1, dp),
                prices[last]*year + maxWineProfit(prices, start, last-1, year+1, dp));
    return dp[start][last] = ans;
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int prices[n];
        for (int i = 0; i < n; ++i) {
            cin>>prices[i];
        }

        // int dp[n][n];
        int dp[100][100] = {0};
        cout<<maxWineProfit(prices, 0, n-1, 1, dp)<<"\n";
    }
    return 0;
}