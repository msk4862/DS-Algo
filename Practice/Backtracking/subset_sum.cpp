#include<bits/stdc++.h>
using namespace std;

void subset1(vector<int> a, int tar, vector<vector<int>>& sol, vector<int> cur={}, int  ind = 0) {

	if(tar == 0) {
		sol.push_back(cur);
		return;
	}

	for (int i = ind; i < a.size(); ++i) {
		if(a[i] <= tar) {
			cur.push_back(a[i]);
			subset1(a, tar-a[i], sol, cur, i+1);
			cur.pop_back();
		}
	}

}

// for handling duplicates
void subset2(vector<int> a, int tar, vector<vector<int>>& sol, vector<int> cur={}, int  ind = 0) {

	if(tar == 0) {
		sol.push_back(cur);
		return;
	}

	for (int i = ind; i < a.size(); ++i) {
		if(i > ind && a[i] == a[i-1]) continue;
		if(a[i] <= tar) {
			cur.push_back(a[i]);
			subset2(a, tar-a[i], sol, cur, i+1);
			cur.pop_back();
		}
	}

}


void solve1(vector<int> a, int tar) {
    vector<vector<int>> sol;

	subset1(a, tar, sol);

	for (auto ar : sol) {
		for (auto e:ar) {
			cout<<e<<", ";
		}
		cout<<endl;
	}
}


void solve2(vector<int> a, int tar) {
    vector<vector<int>> sol;

    sort(a.begin(), a.end());
	subset2(a, tar, sol);

	for (auto ar : sol) {
		for (auto e:ar) {
			cout<<e<<", ";
		}
		cout<<endl;
	}
}


int main() {
	// for no duplicates
	vector<int> a = {1,2,3}; 
    int tar = 3;

    solve1(a, tar);

    cout<<"\nHandling duplicates\n";
    // for handling duplicates
	a = {1,2,1}; 
    tar = 3;
    solve2(a, tar);
}