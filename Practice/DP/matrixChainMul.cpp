// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);

int cost[100][100];

// dimension of nth MAT = MAT[i-1] * MAT[i]
// put braces fom i  to j
int getMinMultOprTD(int mat[], int open, int  close) {
    // matrix invalid 
    if(open == close) return 0;
    
    if(cost[open][close] != -1) return cost[open][close];
    
    cost[open][close] = INT_MAX;
    // put brackets one by one place
    for (int bracket = open; bracket < close; bracket += 1) {
    	// oprs in cur Multiply matrices = (AB)(CD) = row(A)*col(B)*col(D)
    	int curOprs =  getMinMultOprTD(mat, open, bracket) + getMinMultOprTD(mat, bracket+1, close) + mat[open-1]*mat[bracket]*mat[close];
        cost[open][close] = min(cost[open][close], curOprs);
    }
    
    return cost[open][close];
}

void printTable(int cost[][100], int n) {	
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
}

int getMinMultOprBU(int mat[], int n) {
   int cost[n][n]; 
   
   for (int i = 0; i < n; i += 1) {
        cost[i][i] = 0;
   }
   
  for (int k = 0; k < n-1; k += 1) {
    // start = 1 -> beacuse mat[start-1] will not be valid for 0
  	for (int start = 1, end = start + k+1; end < n; start++, end++) {
  		
  		cost[start][end] = INT_MAX;
  		for (int bracket = start; bracket < end; bracket += 1) {
  			 int curOprs = cost[start][bracket] + cost[bracket+1][end] + mat[start-1]*mat[bracket]*mat[end];
  		     cost[start][end] = min(cost[start][end], curOprs);
  		     
  		     //printTable(cost, n);
  		     for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					cout<<cost[i][j]<<" ";
				}
				cout<<endl;
			}
  		}
  	}
  }
   
   return cost[1][n-1];
}

void solve() {   
	int n;
	cin>>n;
	
	int mat[n];
	for (int i = 0; i < n; i += 1) {
		cin>>mat[i];
	}
	
	memset(cost, -1, sizeof(cost));
	cout<<getMinMultOprTD(mat, 1, n-1)<<endl;
	cout<<getMinMultOprBU(mat, n)<<endl;
}

int main() {
    FASTIO
    solve();
    return 0;
}
