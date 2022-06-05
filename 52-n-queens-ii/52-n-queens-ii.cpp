class Solution {
public:
        
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
    
    int solve(vector<string> &board, int r) {
        if(r == board.size()) { 
		    return 1;
    	}
        int ans = 0;
	    for(int c = 0; c < board.size(); c++){
		    if(isSafe(board, r, c)) {
			    board[r][c] = 'Q';   
			    ans += solve(board, r + 1); 
			    board[r][c] = '.';    
		    }
        }
        return ans;

    }
    
        int totalNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        
        return solve(board, 0);
    }
};
