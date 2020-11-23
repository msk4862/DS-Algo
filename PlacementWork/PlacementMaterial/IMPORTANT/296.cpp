//https://leetfree.com/problems/best-meeting-point.html

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


int main() {
	int m, n;
	int grid[m][n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin>>grid[i][j];
		}
	}

	// considering for 1D array by finding median
	vector<int> rows, cols;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if(grid[i][j]) {
				rows.push_back(i);
				cols.push_back(j);
			}
		}
	}

	sort(rows.begin(), rows.end());
	sort(cols.begin(), cols.end());

	// meeting point will be median of row & col
	cout<<rows[rows.size()/2]<<", "<<cols[cols.size()/2]<<endl;
}
