class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        
        int n = matrix[0].size();
        
        int dp[m][n], largest = 0;
                
        for(int i = 0; i< m; ++i) { 
            if(matrix[i][0] == '0')
                dp[i][0] = 0;
            else {
                dp[i][0] = 1;
                largest = 1;                
            }
        }
        
        
        for(int i = 0; i< n; ++i) { 
            if(matrix[0][i] == '0')
                dp[0][i] = 0;
            else {
                dp[0][i] = 1;
                largest =1;
            }
        }
        
        for(int i = 1; i< m; ++i) {
            for(int j = 1; j< n; ++j) {
                if(matrix[i][j] == '1') {
                    int op =  min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
                    if(op == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = op+1;
                    }
                    largest = max(dp[i][j], largest);
                } 
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
            // for(int i = 0; i< m; ++i) {
            //     for(int j = 0; j< n; ++j) {
            //         cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
        
        return largest*largest;
    }
};