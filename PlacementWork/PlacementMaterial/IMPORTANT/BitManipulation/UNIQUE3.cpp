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
	
	int nums[n];
	for (int i = 0; i < n; i += 1) {
		cin>>nums[i];
	}
	
	// counting set bits
	int count[64] = {0};
	for (int i = 0; i < n; i += 1) {
		int ind = 0;
		
		// or ind < 64 would also do
		while((1<<ind) <= nums[i]) {
			if(nums[i]&(1<<ind))
				count[ind]++;
				
			ind++;
		}
	}
	
	int res = 0;
	// now every element will 3n value in count except single element bits
	for (int i = 0; i < n; i += 1) {
		count[i]%=3;
		
		if(count[i])
		res |= 1<<i;
	}
	
	cout<<res<<endl;
}

int main() {
    FASTIO
    solve();
    return 0;
}
