#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void solve() {

	vector<int> ar = {1111,222,298,8,7,6,10,10000};
	int k = 5;
	
	// will contain top k elements
	priority_queue<int, vector<int>, greater<int>> pq_min;
	// insert initial k elements
	for(int i = 0; i < k; ++i) pq_min.push(ar[i]);
	
	for(int i = k; i < ar.size(); ++i) {
		// all k elements must be greater than the rest of the array elements
		// if there is an element greater than minimum element of pq 
		if(!pq_min.empty() && pq_min.top() < ar[i]) {
			pq_min.push(ar[i]);
		}
		
		// will remove the minimum elements
		if(pq_min.size() > k) pq_min.pop();
	}	
	
	while(!pq_min.empty()) {
		cout<<pq_min.top()<<" ";
		pq_min.pop();
	}
	cout<<endl;
}

int main() {
    FASTIO
    solve();
    return 0;
}
