class Solution {
public:
            // O(m + log(n))
    bool solve1(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; ++i) {
            if(mat[i][0] <= target && mat[i][n-1] >= target) {
                
                // binary search
                int l = 0, h = n-1;
                while(l <= h) {
                    int m = (h-l)/2 + l;
                    
                    if(target == mat[i][m]) return true;
                    else if(target > mat[i][m]) l = m+1;
                    else h = m-1;
                }
                
                return false;
            }
        }
        
        return false;
    }
    
    
    // O(m + n)
    bool solve2(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        // can start from left bottom or top right
        int row = m-1, col = 0;
        while (row >= 0 && col < n) {
            if(mat[row][col] == target) return true;
            else if(mat[row][col] < target) col++;
            else row--;
        }
        
        return false;
    }
    
    // O(log(mn)) = O(logm + log n)
    bool solve3(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        // taking whole matrix as single array
        int l = 0, h = m*n-1;
        while(l<=h) {
            int mid = (h-l)/2 + l;
            
            int row = mid / n;
            int col = mid % n;
                        
            if(mat[row][col] == target) return true;
            else if(mat[row][col] < target) l = mid + 1;
            else h = mid-1; 
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        // 1st approach
        // traverse whole matrix
        // O(n^2)
        
        // 2nd approach
        // binary search in each rows
        // O(mlogn)
        
        // 3rd approach
        // binary search in one row only will be required
        // O(m + log(n))
        // return solve1(mat, target);
        
        // 4th approach
        // reducing search space
        // O(m + n)
        // return solve2(mat, target);
        
        // 5th approach
        // taking whole matrix as an sorted array
        return solve3(mat, target);
        
    }
};
