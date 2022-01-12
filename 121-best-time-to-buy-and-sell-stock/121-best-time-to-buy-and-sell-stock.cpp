class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 0;
        vector<int> dp(n, 100001);
        int ans = 0;
        dp[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            if(dp[i-1] < arr[i])
                ans = max(arr[i] - dp[i - 1], ans);
     
                dp[i] = min(dp[i - 1], arr[i]);
        }
        
        return ans;
        
    }
};