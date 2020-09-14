#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {
    int n;
    cin>>n;
    
    ll mat[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>mat[i][j];
        }
    }

    ll mov = 0;
    for (int i = n-1; i > 0; --i) {
        if(mat[i][i-1]+1 != mat[i][i]) {
            mov++;

            // transposing
            for (int k = 0; k <= i; k++) {
                for (int j = 0; j < k; j++) {
                    ll temp = mat[k][j];
                    mat[k][j] = mat[j][k];
                    mat[j][k] = temp;
                }
            }
            
        }
    }

    cout<<mov<<"\n";
    
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