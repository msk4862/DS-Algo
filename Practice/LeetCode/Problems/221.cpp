class Solution {
public:
    int getMaximalSquare(vector<vector<char>> mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int dp[m+1][n+1];
        int res = 0;
        
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(i == 0|| j == 0) dp[i][j] = 0;
                else if(mat[i-1][j-1] == '1') 
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                else dp[i][j] = 0;
                
                res = max(res, dp[i][j]);
            }
        }
        
        return res*res;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        return getMaximalSquare(matrix);
    }
};
