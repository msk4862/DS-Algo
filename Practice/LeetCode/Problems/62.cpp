class Solution {
public:
    
    int uniquePathsHelper1(int m, int n) {
        //as we can see at at ime 
        int dp[2][n];
        
        // we can reach at any pos in 1st row and col in 1 way 
        for(int i = 0; i < n; ++i) dp[0][i] = 1;
        for(int i = 0; i < m; ++i) dp[i][0] = 1;
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                // reaching to i, j pos from top or left block
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
    
    // every time we are just using current row and previous row
    int uniquePathsHelper2(int m, int n) {
        int dp[2][n];
        
        for(int i = 0; i < n; ++i) dp[0][i] = 1;
        
        for(int i = 1; i < m; ++i) {
            dp[i%2][0] = 1;
            for(int j = 1; j < n; ++j) {
                // reaching to i, j pos from top or left block
                dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j];
            }
        }
        
        return dp[(m-1)%2][n-1];
    }
    
    int uniquePaths(int m, int n) {
        // 1st approach 
        // 2d dp
        // O(mn), O(mn)
        // return uniquePathsHelper1(m, n);
        
        // 2nd approach 
        // dp with optimised space complexity
        // O(mn), O(n)
        return uniquePathsHelper2(m, n);
        
        // 3rd approach 
        // combinations
        // total oprations req = (m-1) + (n-1) = m + n -2
        // arrangements of these oprations divide by common opr of R(right) & D will be ans
        // (m+n-2)C(m-1) or (m+n-2)C(n-1)
        // O(r) = Combination Time complexity
    }
};
