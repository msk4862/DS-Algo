#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int gcd(int a, int b) {
 if(b == 0) return a;
 
 return gcd(b, a%b);
}

void solve() {   
	int a, b;
	cin>>a>>b;
	
	cout<<gcd(a, b)<<endl;
}

int main() {
    FASTIO
    solve();
    return 0;
}
