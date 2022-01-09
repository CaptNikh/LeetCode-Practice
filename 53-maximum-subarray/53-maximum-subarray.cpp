class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp(n);
        
        dp[0] = nums[0] < 0 ? 0 : nums[0];
        int maxSoFar = dp[0];
        for(int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + nums[i];
            
            if(dp[i] < 0)
                dp[i] = 0;
            
            maxSoFar = max(dp[i], maxSoFar);
        }
        int x = *max_element(nums.begin(), nums.end());
        
        if(x < 0)
            return x;
        
        return maxSoFar;
        
    }
};