class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        
        int cols = grid[0].size();
        int rows = grid.size();
        for(int i = 0; i < rows; ++i) {
            int s = 0, e = cols-1;
            while(s <= e) {
                int m = (s+e)/2;
                if(grid[i][m] < 0) e=m-1;
                else s=m+1;
            }
            
            if(s < cols) {
                int rem =cols-s; 
                res += rem*((rows-i));
                cols -= rem;
            }
        }
        
        return res;
            
    }
};