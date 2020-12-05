class Solution {
public:
    bool isOutOfBounds(int r, int c, int i, int j) {
        if(i < 0 || j < 0 || i >= r || j >= c) return true;
        return false;
    }
    
    void getGold(vector<vector<int>>& grid, int i, int j, int& maxGold,  int curGold = 0) {
        if(isOutOfBounds(grid.size(), grid[0].size(), i , j) || grid[i][j] == 0) {
            maxGold = max(maxGold, curGold);
            return;
        }
        
        // cout<<
        
        int temp =  grid[i][j];
                
        grid[i][j] = 0;      
        
        getGold(grid, i + 1, j, maxGold, curGold + temp);
        getGold(grid, i - 1, j, maxGold, curGold + temp);
        getGold(grid, i, j + 1, maxGold, curGold + temp);
        getGold(grid, i, j - 1, maxGold, curGold + temp);
        
        grid[i][j] = temp;      
        
        
        return;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<bool>> visited(15, vector<bool> (15, 0));
        
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j])
                    getGold(grid, i, j, res);
            }
        }
        
        return res;
    }
};
