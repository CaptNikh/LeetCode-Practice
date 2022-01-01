class Solution {
public:
    //  Top Down 
//     int climb(int n,vector<int> &dp)
//     {
//         if(n == 0)
//             return 1;
        
//         // Look up
//         if(dp[n] != 0)
//             return dp[n];
        
//         int ans = 0;
//         for(int i = 1; i <= 2; i++)
//         {
//             if(n - i >= 0)
//                 ans += climb(n - i, dp);
//         }
//         return dp[n] = ans;
//     }
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(i - 1 >= 0)
                dp[i] += dp[i - 1];
            if(i - 2 >= 0)
                dp[i] += dp[i - 2];  
        }
        
        return dp[n];
        
    }
};