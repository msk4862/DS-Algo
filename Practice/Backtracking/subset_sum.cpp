#include<iostream>
#include<vector>
using namespace std;

bool isEqual(vector<int> a, int tar) {
	int sum = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		sum+=a[i];
	}

	return sum==tar;
}

void find(vector<int> a, int tar, vector<vector<int>>& sol, vector<int> cur={}, int cur_sum = 0, int  ind = 0) {
	

	if(cur_sum == tar) {
		sol.push_back(cur);
		return;
	}

	if(ind == a.size()) return;

	for (int i = ind; i < a.size(); ++i) {
		if(cur_sum + a[i] <= tar) {
			cur.push_back(a[i]);
			cur_sum += a[i];
			find(a, tar, sol, cur, cur_sum, i+1);
			cur_sum-= cur[cur.size()-1];
			cur.pop_back();
		}
	}

}

int main() {
	int n = 5;
    vector<int> a = {3,2,4,1,5}; 
    int tar = 5;

    vector<vector<int>> sol;

	find(a, tar, sol);

	for (auto ar : sol) {
		for (auto e:ar) {
			cout<<e<<" ";
		}
		cout<<endl;
	}
}