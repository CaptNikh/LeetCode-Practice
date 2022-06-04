class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(vector<string> &board, int r, int c) {
        int n = board.size();
        
	    for(int i = 0; i < n; i++) {
		    if(board[i][c] == 'Q')
                return false; 
		    if(r - i >= 0 && c - i >= 0 && board[r - i][c - i] == 'Q')
                return false;
		    if(r - i >= 0 && c + i <  n && board[r - i][c + i] == 'Q')
                return false;
	    }
	    return true;
    }
    
    void solve(vector<string> &board, int r) {
        if(r == board.size()) { 
		    ans.push_back(board);
		    return;
    	}            
	    for(int c = 0; c < board.size(); c++){
		    if(isSafe(board, r, c)) {
			    board[r][c] = 'Q';   
			    solve(board, r + 1); 
			    board[r][c] = '.';    
		    }
        }

    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return ans;
        
    }
};