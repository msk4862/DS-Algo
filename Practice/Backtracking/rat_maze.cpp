#include<iostream>
using namespace std;

bool isSafe(int maze[][4], int n, int sol[][4], int i, int j) {
	if(i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0 || sol[i][j]==1) return false;
	return true;
}

bool solveMaze(int maze[][4], int n, int sol[][4], int i=0, int j=0) {
	if(i == n-1 and j == n-1) return true;


	if(isSafe(maze, n, sol, i+1, j)) {
		sol[i+1][j] = 1;
		if(solveMaze(maze, n, sol, i+1, j)) return true;
		sol[i+1][j] = 0;
	} 

	if(isSafe(maze, n, sol,i, j+1)) {
		sol[i][j+1] = 1;
		if(solveMaze(maze, n, sol, i, j+1)) return true;
		sol[i][j+1] = 0;
	} 

	if(isSafe(maze, n, sol,i-1, j)) {
		sol[i-1][j] = 1;
		if(solveMaze(maze, n, sol, i-1, j)) return true;
		sol[i-1][j] = 0;
	} 

	if(isSafe(maze, n, sol,i, j-1)) {
		sol[i][j-1] = 1;
		if(solveMaze(maze, n, sol, i, j-1)) return true;
		sol[i][j-1] = 0;
	} 

	return false;
}

int main() {
	int n = 4;
	// cin>>n;

	int sol[4][4] = {0};

	int maze[4][4] = {
		{1, 0, 0, 0},
		{1, 1, 0, 1},
		{0, 1, 0, 0},
		{1, 1, 1, 1}
	};

	sol[0][0] =1;
	solveMaze(maze, n, sol);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout<<sol[i][j]<<" ";
		}
		cout<<endl;
	}
}