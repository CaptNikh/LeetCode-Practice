class Solution {
public:
    struct cell{
        int row;
        int col;
        int time;
    };
    cell cel(int a, int b, int c)
    {
        cell x;
        x.row = a;
        x.col = b;
        x.time = c;
        return x;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<cell> q;
        vector<pair<int, int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    grid[i][j] = -1;
                    q.push(cel(i, j, 0));
            
                }
            }    
        }
        int ans = 0;
        while(!q.empty())
        {
            cell x = q.front();
            q.pop();
            for(int i = 0; i < pos.size(); i++)
            {
                int r = x.row + pos[i].first;
                int c = x.col + pos[i].second;
                
                if(r >= 0 && r < n && c >= 0 && c < m)
                {
                    if(grid[r][c] == 1)
                    {
                        grid[r][c] = -1;
                        q.push(cel(r, c, x.time + 1));
                        ans = max(ans, x.time + 1); 
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
        
    }
};