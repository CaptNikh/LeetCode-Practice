class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int i = g.size() - 1, j = s.size() - 1;
        
        while(j >= 0 and i >= 0)
        {
            if(s[j] >= g[i]){
                ans++;
                j--;
                i--;
            }
            else if(s[j] < g[i])
                i--;
        }
        
        return ans;
        
        
    }
};