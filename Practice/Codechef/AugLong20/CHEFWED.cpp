#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


ll partial(vector<int> fam) {
    int cost = 0;

    vector<set<int>> t(fam.size());
    int k = 0;
    for (int i = 0; i < fam.size(); i++) {
        if(t[k].count(fam[i]) == 0) {  
            t[k].insert(fam[i]);
        } 
        else {
            t[++k].insert(fam[i]);
        }

    }
    

    return k+1;
}

/*
ll get_min(vector<int> fam, int k, int dp[], vector<int> picked = {}, int index = 0) {
    if(index == fam.size())
        return k+get_argument_cost(picked);
    
    // if(dp[index]) return dp[index];

    // cout<<index<<" ";
    picked.push_back(fam[index]);
    int cost_1 = get_min(fam, k, dp, picked, index+1);
    picked.pop_back();

    // taking current guest alone 
    vector<int> t = {fam[index]};
    int cost_2 = get_min(fam, k, dp, t, index+1);
    cost_2 += get_argument_cost(picked) + k;

    return dp[index] = min(cost_1, cost_2);

}
*/

int get_cost(int s, int e, int fam[], int k) {
    if(s == e)
        return k; 

    // unordered_map<int, int> count;
    int count[101] = {0};

    for (int i = s; i <= e; i++) {
        // int k = fam[i];
        count[fam[i]] ++;
    }

    int cost = k;
    for(int i = 0; i <= 100; ++i) 
        if(count[i] > 1)
            cost += count[i];

    return cost;
    
}


int dp[1001][1001] = {0};

int get_min(int s, int e, int fam[], int k) {
    if(s > e)
        return 0;
    if(s == e)
        // one table cost
        return k;

    if(dp[s][e]) return dp[s][e];

    int ans = INT_MAX;
    for(int i = s; i <= e; ++i)
        ans = min(ans, get_cost(s, i, fam, k) + get_min(i+1, e, fam, k));

    dp[s][e] = ans;
    return dp[s][e];
}

void solve() {
    int n, k;
    cin>>n>>k;

    int fam[n];
    for (int i = 0; i < n; i++) {
        cin>>fam[i];
    }

    memset(dp, 0, sizeof(dp[0][0])*1001*1001);

    cout<<get_min(0, n-1, fam, k)<<"\n";
    // cout<<partial(fam)<<"\n";
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}