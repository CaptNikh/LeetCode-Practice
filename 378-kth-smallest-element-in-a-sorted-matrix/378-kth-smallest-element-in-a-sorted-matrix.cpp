class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        
        int n = matrix.size();
        
        auto cmp = [&matrix](pair<int, int> &a, pair<int, int> &b){
                return matrix[a.first][a.second] > matrix[b.first][b.second]; 
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        
        for(int i = 0; i < n; i++)
            pq.push({i, 0});
        
        int ans = 0;
        while(k--)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            int r = p.first;
            int c = p.second;
            ans = matrix[r][c];
            if(c + 1 < n)
                pq.push({r, c + 1});
        }
        
        return ans;
    }
};