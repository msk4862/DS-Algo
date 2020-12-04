#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int maxE(int a[], int n) {
 if(n==0)
	return a[0];
	
	return max(a[n], maxE(a, n-1));
}


int main() {
    FASTIO
    int a[6] = {10, -1, 6, 2, 10, 100};
    cout<<maxE(a, 5);
    return 0;
}	
