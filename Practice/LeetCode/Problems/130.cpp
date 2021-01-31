class Solution {
public:
    void markConnected(vector<vector<char>>& board, int r, int c) {
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == 'X' || board[r][c] == 'M')
            return;
        
        // mark O
        board[r][c] = 'M';
        markConnected(board, r-1, c);
        markConnected(board, r+1, c);
        markConnected(board, r, c-1);
        markConnected(board, r, c+1);
        
        return;
    }

    void solveHelper1(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        // checking top and bottom boundary
        for(int i = 0; i < cols; ++i) {
            if(board[0][i] == 'O') markConnected(board, 0, i);
            if(board[rows-1][i] == 'O') markConnected(board, rows-1, i);
        }
            
        // checking left and right boundary
        for(int i = 0; i < rows; ++i) {
            if(board[i][0] == 'O') markConnected(board, i, 0);
            if(board[i][cols-1] == 'O') markConnected(board, i, cols-1);
        }
            

        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                // Not marked means surrounded
                if(board[i][j] == 'O') board[i][j]  = 'X';
                else if(board[i][j] == 'M') board[i][j]  = 'O';
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 2 || board[0].size() <= 2) return;
        
        // travesre boundary elements and 
        // mark all its connnected O's 
        // O(nm), O(1)
        solveHelper1(board);
    }
};
