class Solution {
public:
     struct comp{
        bool operator() (vector<int> &a, vector<int> &b)
        {
            return a[0]*a[0] + a[1]*a[1] >  b[0]*b[0] + b[1]*b[1];
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<vector<int>, vector<vector<int>> , comp> q(points.begin(), points.end());
        
        vector<vector<int>> ans;
        while(k--)
        {
            ans.push_back(q.top());
            q.pop();
        }
        
        return ans;
    }
};