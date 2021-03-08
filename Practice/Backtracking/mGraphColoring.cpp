// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

bool canColor(vector<vector<int>>& g, int curV, int curColor, vector<int>& colors, vector<int>& vertexColor) {
	// checking if any neighbour has been already colored with curColor
	for (int i = 0; i < g.size(); ++i) {
		if(g[curV][i] && vertexColor[i] == curColor) return false;
	}

	return true;
}

bool isPossible(vector<vector<int>>& g, int curV, vector<int> colors, vector<int>& vertexColor) {
	// all vertices have been coloreds
	if(curV == g.size()) {
		return true;
	}

	for (int i = 0; i < colors.size(); ++i) {
		// if we can color cur vertex with ith color
		if(canColor(g, curV, colors[i], colors, vertexColor)) {
			
			vertexColor[curV] = colors[i];

			// is further coloring possible for current configuration  
			if(isPossible(g, curV+1, colors, vertexColor)) return true;

			// otherwise backtrack
			vertexColor[i] = -1;
		}
	}

	return false;
}

void solve() {   
	int V = 4;
	vector<vector<int>> graph = {
		{ 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
	};
	int m = 3;

	vector<int> colors(m), vertexColor(V, -1);
	for (int i = 0; i < m; ++i) {
		colors[i] = i;
	}

	if(isPossible(graph, 0, colors, vertexColor)) {
		for (int i = 0; i < V; ++i) {
			cout<<vertexColor[i]<<" ";
		}
	}
	else cout<<"Not possible!!";
}

int main() {
    FASTIO
    solve();
    return 0;
}
