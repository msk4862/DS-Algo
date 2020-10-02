#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// checks if its safe to place queen at row,col on board 
bool isSafe(int board[][10], int row, int col, int n) {
	// checking upper rows of the col
	for (int i= 0; i < row; i += 1) {
		if(board[i][col]) return false;
	}
	
	// checking left diagonal
	int i =row-1, j=col-1;
	while(i>=0 && j>=0) {
		if(board[i][j]) return false;
		i--;
		j--;
	}
	
	
	// checking right diagonal
	i =row-1, j=col+1;
	while(i>=0 && j<n) {
		if(board[i][j]) return false;
		i--;
		j++;
	}
	
	return true;
}


bool nqueen(int board[][10], int n, int ind =0) {

	if(ind==n) {
		// have placed all queens on board successfully
		return true;
	}
	
	// have to just solve for current row
	for (int j = 0; j < n; j += 1) {
		if(isSafe(board, ind, j, n)) {
			// placing queen here
			board[ind][j] = 1;
			
			// if rest of the board can't place queen anywhere 
			// remove  queen from current place and continue for loop
			if(!nqueen(board, n, ind+1)) board[ind][j] =0;
			else return true;
		}
	}
	
	return false;
	
}

void solve() { 
	// no.of queens
	int n;
	cin>>n;
	
	// place n queens on board
	int board[10][10] = {0};
	nqueen(board, n);
	
	for (int i = 0; i < n; i += 1) {
		for (int j = 0; j < n; j += 1) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	
}

int main() {
    FASTIO
    solve();
    return 0;
}		
