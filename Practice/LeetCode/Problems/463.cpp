class Solution {
public:
    int islandPerimeterHelper(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 1;
        if(grid[r][c] == -1) return 0;
        
        grid[r][c] = -1;
        return islandPerimeterHelper(grid, r-1, c) + islandPerimeterHelper(grid, r, c-1) + islandPerimeterHelper(grid, r+1, c) + islandPerimeterHelper(grid, r, c+1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j< grid[0].size(); ++j) {
                if(grid[i][j] == 1)
                    return islandPerimeterHelper(grid, i, j);
            }
        }
        
        return -1;
    }
};
