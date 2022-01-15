class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        if(n == 1)
            return {{1}};
        if( n == 2)
            return {{1}, {1, 1}};
        vector<vector<int>> dp(n);
        // Base cases
        dp[0] = {1};
        dp[1] = {1, 1};
        for(int i = 2; i < n; i++)
        {
            vector<int> ans(i + 1);
            
            ans[0] = 1, ans[i] = 1;
            
            for(int j = 1; j < i; j++)
            {
                ans[j] = dp[i - 1][j -1] + dp[i - 1][j];
            }
            dp[i] = ans;
        }
        
        return dp;
        
    }
};