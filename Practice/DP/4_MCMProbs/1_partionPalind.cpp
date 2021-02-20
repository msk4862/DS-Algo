// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

bool isP(string s) {
	string str = s;
	reverse(s.begin(), s.end());
	return str.compare(s) == 0 ? true: false;
}


    // we have n*n subproblems to solve and each is taking O(n) time
    // O(n^3)
int minCuts_td(string str, int i, int j, int dp[][1000]) {
    // cout<<isP(str.substr(i, j-i+1)) <<str.substr(i, j-i+1)<<endl;
    if(i == j || isP(str.substr(i, j-i+1))) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int min_cuts = INT_MAX;
    for(int k = i; k < j; ++k) {
        int cost = minCuts_td(str, i, k, dp) + minCuts_td(str, k+1, j, dp) + 1;
        min_cuts = min(min_cuts, cost);
    }

    return dp[i][j] = min_cuts;
}



int main() {

	string str;
	cin>>str;
    int n = str.size();

    int dp[n+1][1000];
    memset(dp, -1, sizeof(int)*(n+1)*1000);

    cout<<minCuts_td(str, 0, str.size()-1, dp)<<"\n";

    return 0;
}


// 2nd approach
// optimised
class Solution {
public:
    
    bool isP(string s, int st, int end) {
        while(st < end) {
            if(s[st] != s[end]) return false;
            ++st;
            --end;
        }
        return true;
    }

    int minCuts_td(string str, int i, int j, int dp[][2001]) {
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(isP(str, i, j)) return dp[i][j] = 0;
        
        int min_cuts = INT_MAX;
        for(int k = i; k < j; ++k) {
            if(isP(str, i, k)) {
                int cost = minCuts_td(str, k+1, j, dp) + 1;
                min_cuts = min(min_cuts, cost);
            }
        }

        return dp[i][j] = min_cuts;
    }
    
    int minCut(string s) {
        int n = s.size();

        int dp[n+1][2001];
        memset(dp, -1, sizeof(int)*(n+1)*2001);

        return minCuts_td(s, 0, n-1, dp);
    }
};