#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[n-j-1][i];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // transposing matrix
        for(int  i = 0; i < n; ++i) {
            for(int  j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
         
        // reversing each ow
        for(int  i = 0; i < n; ++i) {
            for(int  j = 0; j < n/2; ++j) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }              
                
    }
};
