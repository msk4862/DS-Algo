// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int lis_bu(vector<int> nums) {
    int  n = nums.size();
    int dp[n+1];
    
    dp[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j < i; ++j) {
            if(nums[j-1] < nums[i-1])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    return *max_element(dp, dp+n+1);
}


int main() {
    vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 }; 

    cout<<lis_bu(arr)<<endl;
    return 0;
}