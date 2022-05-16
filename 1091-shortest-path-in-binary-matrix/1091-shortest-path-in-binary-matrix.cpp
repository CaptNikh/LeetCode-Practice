class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        
         if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) {
            return -1;
        }
        
        vector<pair<int, int>> paths = {{-1, -1}, {-1, 0}, {-1, 1}, {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}};
        
        vector<vector<int>> visited (row, vector<int> (col, 0));
        
        int res = 0;
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        visited[0][0] = 1;
        int ans = 0;
        while(!q.empty()) {
            
            int sz = q.size();
            ans++;
            
            for(int i = 0; i < sz; i++) {
                
                auto p = q.front();
                q.pop();
                
                int r = p.first;
                int c = p.second;
                
                if(r == row - 1 and c == col - 1)
                        return ans;
                
                for(auto &k : paths) {
                    
                    int nr = r + k.first;
                    int nc = c + k.second;  
                    
                    if(nr >= 0 and nr < row and nc >= 0 and nc < col and visited[nr][nc] == 0 and grid[nr][nc] == 0){
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            
            }
        }
        
        return -1;
    }
};