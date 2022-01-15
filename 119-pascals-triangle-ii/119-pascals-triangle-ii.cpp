class Solution {
public:
    vector<int> getRow(int n) {
        if(n == 0)
            return {1};
        if(n == 1)
            return {1, 1};
        
        
        vector<int> prev = {1,1};
        vector<int> res;
        for(int i = 2; i <= n; i++)
        {
            vector<int> ans(i + 1);
            ans[0] = 1, ans[i] = 1;
            
            for(int j = 1; j < i; j++)
            {
                ans[j] = prev[j - 1] + prev[j];
            }
            
            prev = ans;
        }
        
        return prev;
        
    }
};