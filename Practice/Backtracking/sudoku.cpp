#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

// if we can fill n in row, col on board
bool canFill(int sud[][9], int row, int col, int n) {

	// checking row
	for (int i = 0; i < 9; i += 1) {
		if(sud[row][i] == n) return false;
	}

	// checking col
	for (int i = 0; i < 9; i += 1) {
		if(sud[i][col] == n) return false;
	}

	int gr = row%3, gc=col%3;
	
	// checking local 3*3 box of n
	for (int i = 0; i < 3; i += 1) {
		for (int j = 0; j < 3; j += 1) {
			if(sud[i+gr*3][j+gc*3] == n) return false;
		}
	}
	
	return true;
}

bool solveSudoku(int sudoku[][9], int row = 0, int col = 0) {
	if(row == 8 && col==9) return true;
	
	if(col == 9) {
		col=0;
		row++;
	}
	
	if(sudoku[row][col]) return solveSudoku(sudoku, row, col+1);
	
	// can fill 1 from 9 in the cell
	for (int n = 1; n <= 9; n += 1) {
		if(canFill(sudoku, row, col, n)) {
			sudoku[row][col] = n;

			
			// if rest of sudoku can't be solved
			// choose another number
			if(solveSudoku(sudoku, row, col+1)) return true; 
			sudoku[row][col] = 0;
		}
	}
	
	// no number is possible
	return false;
	
}

void solve() {   
	
	// initial sudoku
	int sudoku[9][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
	   {5, 2, 0, 0, 0, 0, 0, 0, 0},
	   {0, 8, 7, 0, 0, 0, 0, 3, 1},
	   {0, 0, 3, 0, 1, 0, 0, 8, 0},
	   {9, 0, 0, 8, 6, 3, 0, 0, 5},
	   {0, 5, 0, 0, 9, 0, 6, 0, 0},
	   {1, 3, 0, 0, 0, 0, 2, 5, 0},
	   {0, 0, 0, 0, 0, 0, 0, 7, 4},
	   {0, 0, 5, 2, 0, 6, 3, 0, 0}

	};
         
   cout<<solveSudoku(sudoku)<<endl;

   
	for (int i = 0; i < 9; i += 1) {
		for (int j = 0; j < 9; j += 1) {
			cout<<sudoku[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
}

int main() {
    FASTIO
    solve();
    return 0;
}
