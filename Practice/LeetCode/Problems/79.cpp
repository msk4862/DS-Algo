class Solution {
public:
    bool isExist(vector<vector<char>>& board, string& word, int wordInd, int i, int j) {
        if(wordInd == word.size()) return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        
        if(board[i][j] != word[wordInd]) return false;
        
        char orgChar = board[i][j];
        board[i][j] = '.';
        
        bool isFoundF = isExist(board, word, wordInd+1, i, j+1);
        bool isFoundD = isExist(board, word, wordInd+1, i+1, j);
        bool isFoundU = isExist(board, word, wordInd+1, i-1, j);
        bool isFoundB = isExist(board, word, wordInd+1, i, j-1);
        
        if(isFoundF || isFoundB || isFoundU || isFoundD) return true;
        
        // restore board value
        board[i][j] = orgChar;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isExist(board, word, 0, i, j)) return true;   
            }
        }    
        
        return false;
    }
};
