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
		subset(a, n, res, i+1, cur);
		cur.pop_back();
	}
	return;
	
}

void solve() { 
	int n;
	cin>>n;  
	int a[n];
	for(int i =0; i < n;++i) {
		cin>>a[i];
	}
	
	vector<vector<int>> res;
	subset(a, n, res);
	
	for(auto i: res) {
		if(i.size() ==0) {
			cout<<"null \n";
			continue;
		}
		for(auto e: i){
			cout<<e<<" ";
		}
		cout<<endl;
	}
}

int main() {
    FASTIO
    solve();
    return 0;
}		
