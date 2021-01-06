class Solution {
public:
    /*
        // 1st approach
        // Time: O(m*n)
        // spae: O(m+n)
        
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> rows(m, -1);
        vector<int> cols(n, -1);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(rows[i] == 0 || cols[j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        
    }
    */
    
    // 2nd approach
    // use 0th row and col of matrix iself as a dummy array instead of extra spce
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool row = false, col=false;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i!=0 && j!=0 && matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                }
                
                // a zero in 1st row iself
                if(matrix[i][j] == 0 && !row && i == 0) row = true;

                // a zero in 1st col iself
                if(matrix[i][j] == 0 && !col && j == 0) col = true;
            }    
        }
                
        // starting from end to avoid currently written zero to behave like original zero
        // in dummy array - 0th col and 0th row
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0 || (row && i==0) || (col && j==0)) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
    
};
