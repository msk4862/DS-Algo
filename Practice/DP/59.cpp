class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n , vector<int>(n));
        
        int start = 0;
        
        int count = 1;
        while(start <= n/2) {
            // forward
            for(int i = start; i < n-start; ++i) {
                mat[start][i] = count++;
            }
            
            // downward
            for(int i = start+1; i < n-start; ++i) {
                mat[i][n-start-1] = count++;
            }
            
            // backward
            for(int i = n-start-2; i >= start; --i) {
                mat[n-start-1][i] = count++;
            }
            
            // upward
            for(int i = n-start-2; i > start; --i) {
                mat[i][start] = count++;
            }
            
            start++;
            cout<<start<<" ";
        }
        
        return mat;
    }
};
