#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int get(int a[][100], int i, int j, int n, int m) {
    if(i<0 or  i>=n or j < 0 or j >= m)
        return 0;
    return a[i][j];
}

void solve() {
    int n, m;
    cin>>n>>m;

    int a[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>> a[i][j];
        }
    }

    set<int> adj;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j]!=-1 and adj.find(a[i][j])==adj.end()) {

                if(get(a, i-1, j, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i, j-1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i-1, j-1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i-1, j+1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i+1, j, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i, j+1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i+1, j+1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
                else if(get(a, i-1, j+1, n, m) == a[i][j]) {
                    adj.insert(a[i][j]);
                    continue;
                }
            }
        }
    }
    // for(auto e:adj) cout<<e<<" ";
    cout<<adj.size()<<"\n";
    
}

int main() {
    // FASTIO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}