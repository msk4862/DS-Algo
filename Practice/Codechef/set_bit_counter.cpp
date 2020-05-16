#include<bits/stdc++.h>
using namespace std;

int count_min_jump(int n) {
    int set_bits = 0;
    while(n > 0) {
        n &= (n-1);
        set_bits++;
    }

    return set_bits;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<count_min_jump(n)<<"\n";
    }
}