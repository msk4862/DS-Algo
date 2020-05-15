#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, count=0;
    vector<int> dna;
    cin>>t;
    while(t--) {
        count=0;
        cin>>n>>k;
        for (int i = 0; i < n; i++) {
            int e;
            cin>>e;
            if((e+k)%7 == 0) {
                ++count;
            }
        }
        
        cout<<count<<"\n";
        
    }

}