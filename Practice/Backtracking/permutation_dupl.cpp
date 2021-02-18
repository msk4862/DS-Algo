// For array that may have duplicate values

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

/*
The idea is for each recursion level, swap the current element at 1st index with each element that comes after it (including itself). For example, permute[1,2,3]:

At recursion level 0, current element at 1st index is 1, there are 3 possibilities: [1] + permute[2,3], [2] + permute[1,3], [3] + permute[2,1].

Take "2+permute[1,3]" as the example at recursion level 0. At recursion level 1, current elemenet at 1st index is 1, there are 2 possibilities: [2,1] + permute[3], [2,3] + permute[1].

... and so on.

Let's look at another example, permute[1,2,3,4,1].

At recursion level 0, we have [1] + permute[2,3,4,1], [2] + permute[1,3,4,1], [3] + permute[2,1,4,1], [4] + permute[2,3,1,1], [1] + permute[2,3,4,1].

1 has already been at the 1st index of current recursion level, so the last possibility is redundant. We can use a hash set to mark which elements have been at the 1st index of current recursion level, so that if we meet the element again, we can just skip it.

*/


// for complexity: we will have n! leaf nodes at max
// and for each leaf node we have branch of depth n => O(n!*n)
void permute(vector<int> ar, int first, int n, vector<vector<int>>& res) {
	if(first == n) res.push_back(ar);

	unordered_set<int> hasBeenFirst;
	for (int i = first; i < n; ++i) {
		if(hasBeenFirst.count(ar[i]) > 0) continue;
		
		// fixes at first
		hasBeenFirst.insert(ar[i]);

		// operation
		// fixing ith no. as first and then permuting rest of the digits
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