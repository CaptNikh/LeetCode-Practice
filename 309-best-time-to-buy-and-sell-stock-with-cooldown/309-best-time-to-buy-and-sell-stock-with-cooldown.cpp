class Solution {
public:
    int maxprofit(int i, int j, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(j == 0)
        {
            int buy = maxprofit(i + 1, 1, prices, dp) - prices[i];
            int cooldown = maxprofit(i + 1, 0, prices, dp);
            
            return dp[i][j] = max(buy, cooldown);
        }
        else
        {
            int sell = maxprofit(i + 2, 0, prices, dp) + prices[i];
            int cooldown = maxprofit(i + 1, 1, prices, dp);
            return dp[i][j] = max(sell, cooldown);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int> (2, -1));
        
        // 0 for buying 1 for selling
        return maxprofit(0, 0,prices, dp);
    }
};