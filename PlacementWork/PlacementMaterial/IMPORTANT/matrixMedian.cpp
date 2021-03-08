// https://www.geeksforgeeks.org/find-median-row-wise-sorted-matrix/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int countNums(vector<vector<int>>& mat, int val) {
	/*
		Returns values that are equal or smaller than val
	*/

	int r = mat.size();
	int c = mat[0].size();

	int count = 0;
	// for each row count no. of elements less than equal to val
	for (int i = 0; i < r; ++i)	{

		count += upper_bound(mat[i].begin(), mat[i].end(), val) - mat[i].begin();

		// user-defined		
		/*
		int l = 0, h = c-1;
		while(l <= h) {
			int mid = (h-l)/2 + l;
			// cout<<mid<<" ";
			if(mat[i][mid] <= val) l = mid+1;
			else h = mid-1;
		}*/

		// count += h+1;
	}

	return count;
}

int median1(vector<vector<int>>& mat) {
	int minV = INT_MAX, maxV = INT_MIN;

	int r = mat.size();
	int c = mat[0].size();
	int med = (r*c + 1)/2;

	// O(r)
	for (int i = 0; i < r; ++i) {
		minV = min(mat[i][0], minV);
		maxV = max(mat[i][c-1], maxV);
	}

	// int l = minV, h = maxV;
	// for each mid, count how many nums are there
	// less than mid
	// value of maxV in worst case will 2^32 - 1 => log(2^32) = 32
	while(minV <= maxV) {
		int mid = (maxV-minV)/2 + minV;

		// O(r*log(c)) (log(columns) for each row)
		int count = countNums(mat, mid);

		if(count < med) minV = mid+1;
		else maxV = mid-1;
	}

	return minV;
}

void solve() {   
	vector<vector<int>> mat = {
		{1,3,7},
		{2,7,9},
		{3,8,9}
	};
	// vector<vector<int>> mat = {
	// 	{1},
	// 	{2},
	// 	{3}
	// };
	/*
	Brute force appoach:
	Store all elements in an array and sort that array 
	time: O((r*c)log(r*c)), space: O(r*c)
	*/


	/*
	Binary search appoach:
	median value will have r*c/2 nums that are less than it
	time: O(32*r*log(c)), space: O(1)
	*/
	cout<<median1(mat)<<" ";

}

int main() {
    FASTIO
    solve();
    return 0;
}