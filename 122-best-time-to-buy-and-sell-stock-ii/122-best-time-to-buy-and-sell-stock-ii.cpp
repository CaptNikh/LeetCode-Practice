class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        vector<int> dp(n, 100001);
        if(n == 1)
            return 0;
        int ans = 0;
        dp[0] = prices[0];
        for(int i = 1; i < n; i++)
        {
            if(dp[i - 1] < prices[i])
            {
                ans += prices[i] - dp[i - 1];
                dp[i] = prices[i];
            }
            else
            {
                dp[i] = min(dp[i - 1], prices[i]);
            }
        }
        return ans;
    }
};