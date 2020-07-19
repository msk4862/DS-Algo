#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

ll solve() {
    int n, k;
    cin>>n>>k;

    int candies, ans = 0;
    while(n--) {
        cin>>candies;
        ans += candies/k;
    }

    return ans;
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        cout<<solve()<<"\n";
    }
    return 0;
}