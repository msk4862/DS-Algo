// For array having no duplicates

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// for complexity: we will have n! leaf nodes at max
// and for each leaf node we have branch of depth n => O(n!*n)
void permute(vector<int> ar, int first, int n, vector<vector<int>> &res) {
	if(first == n) res.push_back(ar);

	for (int i = first; i < n; ++i) {
		// operation
		swap(ar[first], ar[i]);
		
		// recur
		permute(ar, first+1, n, res);
		
		// backtrack
		swap(ar[i], ar[first]);
	}
}

void solve() {   
	int n;
	cin>>n;

	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		cin>>ar[i];	
	}
	sort(ar.begin(), ar.end());
	vector<vector<int>> res;
	permute(ar, 0, n, res);

	for(auto v : res) {
		for(int e : v) cout<<e<<" ";
		cout<<endl;
	}
}


int main() {
    FASTIO
    solve();
    return 0;
}