class Solution {
public:
    vector<vector<bool>> visited;
    bool search(int i, int j, int index, vector<vector<char>> &board, string &word) {
        if(index == word.size())
            return true;
        
        if(i < 0||i >= board.size()||j < 0||j >= board[0].size()||board[i][j] != word[index]||visited[i][j])
            return false;
       
            
        visited[i][j] = true;
        
        if(search(i + 1, j, index + 1, board, word) ||
           search(i, j + 1, index + 1, board, word) || 
           search(i - 1, j, index + 1, board, word) ||
           search(i, j - 1, index + 1, board, word))
        return true;
        
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        visited.resize(rows, vector<bool> (cols, false));
        
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0] && search(i, j, 0,board, word))
                    return true;
            }
        }
        
        return false;
    }
};