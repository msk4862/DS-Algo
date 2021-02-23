class Solution {
public:
    int getTotalPaths(vector<vector<int>>& g, int i, int j, int emptyCnt) {
        if(i<0 || i>= g.size() || j<0 || j>=g[0].size() || g[i][j] == -2) return 0;
        
        // cant walk
        if(g[i][j] == -1) return 0;
        
        // found
        // if visted all empty => return 1
        // else => return 0;
        if(g[i][j] == 2) return emptyCnt == 0;
        
        int orgVal = g[i][j];
        // mark vistied
        g[i][j] = -2;
        
        // visited one empty empty
        emptyCnt -= 1;
        
        int ways = getTotalPaths(g, i-1, j,  emptyCnt) + getTotalPaths(g, i, j-1, emptyCnt) + getTotalPaths(g, i+1, j, emptyCnt) + getTotalPaths(g, i, j+1, emptyCnt);
        
        // restore value
        g[i][j] = orgVal;
        
        return ways;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int emptyCnt = 0;
        pair<int, int> start;
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) { 
                if(grid[i][j] == 0)
                    emptyCnt++;
                if(grid[i][j] == 1)
                    start = {i, j};
            }
        }
        
        // emptyCnt is one extra for compensating one decrement on starting point
        return getTotalPaths(grid, start.first, start.second, emptyCnt+1);
    }
};
