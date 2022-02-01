class Solution {
public:
    
    void dfs(int i, int j, vector<vector<char>>& grid, vector<pair<int,int>> &directions)
    {
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int k = 0; k < directions.size(); k++)
        {
            int r = i + directions[k].first;
            int c = j + directions[k].second;
            
            if(r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == '1')
            {
                dfs(r, c, grid, directions);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid, directions);
                }
            }
        }
        return cnt;
    }
};