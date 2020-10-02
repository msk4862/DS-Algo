#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

void subset(int a[], int n, vector<vector<int>>& res, int ind=0, vector<int> cur = {}) {
	res.push_back(cur);
	for (int i = ind; i < n; i += 1) {
		cur.push_back(a[i]);
		subset(a, i+1, n, res, cur);
		cur.pop_back();
	}
	
	return;
	
}

void solve() { 
	int n = 6;  
	int a[] = {2,3,4,5,6,7};
	
	vector<vector<int>> res;
	subset(a, n, res);
}

int main() {
    FASTIO
    solve();
    return 0;
}		
