class Solution {
public:
    vector<pair<int, int>> paths = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    
        if(dp[i][j] != 0)
            return dp[i][j];
        
        int ans = 0; 
        
        for(auto &p : paths) {
            int nr = i + p.first;
            int nc = j + p.second;
            
            if(nr >= 0 and nr < matrix.size() and nc >= 0 and nc < matrix[0].size() and matrix[nr][nc] > matrix[i][j])
                ans = max(ans, dfs(nr, nc, matrix, dp));
            // else
            //     continue;
        }
                         
        return dp[i][j] = ans + 1;
        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if(matrix.size() == 0)
            return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int> (m, 0));    
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sub_res = dfs(i, j, matrix, dp);
                res = max(res, sub_res);
            }
        }
        
        return res;
    }
};