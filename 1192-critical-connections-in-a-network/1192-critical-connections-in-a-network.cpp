class Solution {
public:
    
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    vector<int> fTime, mTime, visited; 
    int time = 0;
    
    void countBridgesDfs(int root, int parent) {
        
        mTime[root] = time, fTime[root] = time;
        time++; 
        visited[root] = true; 
        
        for(auto &child : adj[root]) {
            if(child == parent)
                continue;
            if(!visited[child])
                countBridgesDfs(child, root);
            mTime[root] = min(mTime[child], mTime[root]);
            if(fTime[root] < mTime[child])
                ans.push_back({root, child});   
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        adj.resize(n, vector<int>());
        visited.resize(n, 0), mTime.resize(n), fTime.resize(n);
        
        for(int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        countBridgesDfs(0, -1);
        
        return ans;
        
    }
};