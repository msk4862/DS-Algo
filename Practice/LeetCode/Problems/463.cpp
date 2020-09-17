class Solution {
public:
    int traverse(vector<vector<int>>& grid, int i, int j) {
        if(i<0 or j<0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0) return 1;
            
        // travelled
        if(grid[i][j] == -1)
            return 0;
        
            cout<<i<<j<<" ";
        
        grid[i][j] = -1;
        return traverse(grid, i-1, j) + traverse(grid, i+1, j) + traverse(grid, i, j+1) + traverse(grid, i, j-1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, f=0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]) {
                    ans = traverse(grid, i, j);
                    f = 1;
                    break;
                }
            }
            if(f) break;
            
        }
        
        return ans;
    }
};
