class Solution {
public:
    struct cell{
        int row;
        int col;
        int dis;
    };
    
    cell cel(int a, int b, int c)
    {
        cell x;
        x.row = a;
        x.col = b;
        x.dis = c;
        
        return x;    
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> visited (n, vector<int> (m, 0));
        vector<pair<int, int>> pos = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<cell> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    visited[i][j] = 1;
                    q.push(cel(i, j, 0));
                }
            }
        }
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
                    if(!visited[r][c])
                    {
                        visited[r][c] = 1;
                        q.push(cel(r, c, x.dis + 1));
                        mat[r][c] = x.dis + 1;
                    }
                }
            }
        }
        
        
        return mat;
        
        
       
        
    }
};