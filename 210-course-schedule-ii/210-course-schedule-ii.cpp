class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {
        
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < arr.size(); i++)
        {
            adj[arr[i][1]].push_back(arr[i][0]);
        }
    
        vector<int> indeg(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++)
        {
            for(int j = 0; j < adj[i].size(); j++)
                indeg[adj[i][j]]++;
        }
        
        vector<int> top_sort;
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            top_sort.push_back(x);
            
            for(int j = 0; j < adj[x].size(); j++)
            {
                indeg[adj[x][j]]--;
                if(indeg[adj[x][j]] == 0)
                    q.push(adj[x][j]);
            }
        }
        
            
        if(top_sort.size() == numCourses)
    
            return top_sort;
        else{
            top_sort.clear();
            return top_sort;
        }
    }
};