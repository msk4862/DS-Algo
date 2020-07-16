#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int solve(int k) {
    char chess[8][8];

    chess[0][0]  = 'O';
    k -=1;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(i==0 and j == 0) continue;
            
            if(k > 0) {
                chess[i][j] = '.';
                k--;
            }
            else chess[i][j] = 'X';
        }
        
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout<< chess[i][j];
        }
        cout<<"\n";
    }
}

int main() {
    FASTIO;
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>k;
        solve(k);
        
    }
    return 0;
}