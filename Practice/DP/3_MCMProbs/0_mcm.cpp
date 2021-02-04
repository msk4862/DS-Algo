#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int minOprs_td(vector<int> arr, int i, int j, int dp[][1000]) {
    if(i >= j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int min_oprs = INT_MAX;
    for(int k = i; k < j; ++k) {
        int cost = minOprs_td(arr, i, k, dp) + minOprs_td(arr, k+1, j, dp) + arr[i-1]*arr[k]*arr[j];
        min_oprs = min(min_oprs, cost);
    }

    return dp[i][j] = min_oprs;
}



int main() {

    vector<int> arr = {10, 20, 30, 40, 30};
    int n = arr.size();

    int dp[n+1][1000];
    memset(dp, -1, sizeof(int)*(n+1)*1000);

    cout<<minOprs_td(arr, 1, arr.size()-1, dp)<<"\n";

    return 0;
}