class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // storing matrix as an array and sorting it all -> nmlog(nm)
        
        // will store all diagonals - > less time complexity
        int m = mat.size();
        int n = mat[0].size();
        
        // upper half
        for(int k = 0; k < n; ++k) {
            int i, j;
            
            vector<int> dia;
            for(i = 0, j = k; i < m && j < n; ++i, ++j) {
                dia.push_back(mat[i][j]);
            }
            
            sort(dia.begin(), dia.end());
            
            // replace 
            for(i = 0, j = k; i < m && j < n; ++i, ++j) {
                mat[i][j] = dia.front();
                dia.erase(dia.begin());
            }
        }
        
        // lower half
        for(int k = 1; k < m; ++k) {
            int i, j;
            
            vector<int> dia;
            for(i = k, j = 0;i < m && j < n; ++i, ++j) {
                dia.push_back(mat[i][j]);
            }
            
            sort(dia.begin(), dia.end());
            
            // replace 
            for(i = k, j = 0;i < m && j < n; ++i, ++j) {
                mat[i][j] = dia.front();
                dia.erase(dia.begin());
            }
        }
        
        return mat;
    }
};