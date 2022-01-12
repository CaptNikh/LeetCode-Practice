class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =  prices.size();
        // vector<int> dp(n, 100001);
        int minP = prices[0];
        if(n == 1)
            return 0;
        int ans = 0;
        // dp[0] = prices[0];
        for(int i = 1; i < n; i++)
        {
            if(minP < prices[i])
            {
                ans += prices[i] - minP;
                minP = prices[i];
            }
            else
            {
                minP = min(minP, prices[i]);
            }
        }
        return ans;
    }
};