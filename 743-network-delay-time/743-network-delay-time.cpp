class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        
        
        for(int i = 0; i < (int)times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n + 1, false);
        
        vector<int> dist(n + 1, INT_MAX);
        
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()) {
            int prev_dis = pq.top().first;
            int prev_pos = pq.top().second;
            
            pq.pop();
            
            for(auto i : graph[prev_pos]) {
                
                int next_pos = i.first;
                int next_dis = i.second;
                
                if(dist[next_pos] > dist[prev_pos] + next_dis) {
                    dist[next_pos] = dist[prev_pos] + next_dis;
                    pq.push({ dist[next_pos], next_pos});
                }
            }
        }
        
        
        int res = INT_MIN;
        
        for(int i = 1; i <= n; i++) {
            if(dist[i] > res)
                res = dist[i];
            // cout << dist[i] << " ";
        }
        
        return res == INT_MAX ? -1 : res;
        
    }
};