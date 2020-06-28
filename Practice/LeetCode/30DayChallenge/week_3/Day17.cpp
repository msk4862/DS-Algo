/*
    Number of Islands
*/

class Solution {
public:
    void traverseIsland(vector<vector<char>>& grid, int i, int j, int r, int c) {
        if(i<0 or j<0 or i>=r or j>=c or grid[i][j]!='1')
            return;
        
        cout<<i<<j<<" ";
        // mark travelled
        grid[i][j] = '2';
        traverseIsland(grid, i-1, j, r,c);
        traverseIsland(grid, i, j-1,r,c);
        traverseIsland(grid, i+1, j,r,c);
        traverseIsland(grid, i, j+1,r,c);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int nums = 0;
        
        int r = grid.size();
        if(r == 0) return 0;
        
        int c = grid[0].size();
        
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                if(grid[i][j] == '1') {
                    nums++;
                    traverseIsland(grid, i, j, r, c);
                }
            }
        }
        
        return nums;
    }
};