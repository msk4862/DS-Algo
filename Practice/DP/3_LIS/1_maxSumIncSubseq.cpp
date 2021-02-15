// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int maxSumIncSub(vector<int> nums) {
    int  n = nums.size();
    int dp[n+1];
    
    dp[0] = 0;
    
    for(int i = 1; i <= n; ++i) {
        dp[i] = nums[i-1];
        for(int j = 1; j < i; ++j) {
            if(nums[j-1] < nums[i-1])
                dp[i] = max(dp[i], dp[j]+nums[i-1]);
        }
    }
    
    return *max_element(dp, dp+n+1);
}


int main() {
    vector<int> arr = {1, 101, 2, 3, 100, 4, 5};  

    cout<<maxSumIncSub(arr)<<endl;
    return 0;
}