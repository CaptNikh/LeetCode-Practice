class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>> & board, vector<pair<int, int>> &directions)
    {
        if(board[i][j] == 'X' || board[i][j] == '1')
           return;
         
         board[i][j] = '1';
         int n = board.size();
         int m = board[0].size();
           
         for(int k = 0; k < directions.size(); k++)
         {
            int r = i + directions[k].first;
            int c = j + directions[k].second;
             
             if(r >= 0 and r < n and c >= 0 and c < m and board[r][c] == 'O')
                 dfs(r, c, board, directions);
                 
         }
         
    }
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < m; i++)
        {
            dfs(0, i, board, directions);
            dfs(n - 1, i, board, directions);
        }
        
        for(int i = 0; i < n; i++)
        {
            dfs(i, 0, board, directions);
            dfs(i, m - 1, board, directions);
        }
        
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                
                else if( board[i][j] == 'O')
                    board[i][j] = 'X';
            }
                
        }
        return;
    }
};