class Solution {
public:
    int profit(vector<int> &prices, vector<vector<int>> &dp, int i, int j, int fee)
    {
        if(i >= prices.size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(j == 0)
        {
            int x = profit(prices, dp, i + 1, 1, fee)  - prices[i];
            int y = profit(prices, dp, i + 1, 0, fee);
            
            return dp[i][j] = max(x, y);
        }
        else
        {
            int x = profit(prices, dp, i + 1, 0, fee) + prices[i] - fee;
            int y = profit(prices, dp, i + 1, 1, fee);
            return dp[i][j] = max(x, y);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return profit(prices, dp, 0, 0, fee);
    }
};