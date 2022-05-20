class Solution {
public:
    vector<vector<int>> paths = {{0, 1}, {1, 0}};
    
    int dfs(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp){
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        
        int n = arr.size();
        int m = arr[0].size();
        
        
        int ans = 0;
        
        for(int k = 0; k < paths.size(); k++) {
            
            int r = i + paths[k][0];
            int c = j + paths[k][1];
            
            if(r >= 0 && r < n && c >= 0 && c < m and arr[r][c] != 1){
                ans += dfs(r, c, arr, dp);
            }
        }
        
        if(i == n - 1 and j == m - 1)
            return dp[i][j] = 1;
        
        return dp[i][j] = ans;
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        
        int n = arr.size();
        int m = arr[0].size();
        
        if(arr[n - 1][m - 1] == 1 || arr[0][0] == 1)
            return 0;
        
        vector<vector<int>> dp(n, vector<int> (m, -1));
        int res = dfs(0, 0, arr, dp);
        
        // for(auto &i : dp) {
        //     for(auto &j : i)
        //         cout << j << " ";
        //     cout << '\n';
        // }
        
        return res;
    }
};