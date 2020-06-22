#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int cacheHits(int n, int b, int m, vector<int> ar ) {
    int curBlock, blockNum;

    int nums = 0;

    curBlock = ar[0]/b;
    nums+=1;

    for (int i = 1; i < m; i++) {
        blockNum = ar[i]/b;

        if(curBlock != blockNum) {
            nums+=1;
            curBlock = blockNum;
        }
    }

    return nums;
    
}

int main() {
    FASTIO;
    int t, n, b ,m;
    cin>>t;
    while(t--) {
        cin>>n>>b>>m;
        vector<int> ar(m);
        for (int i = 0; i < m; i++) {
            cin>>ar[i];
        }
        cout<<cacheHits(n, b , m, ar)<<"\n";
        
    }
    return 0;
}