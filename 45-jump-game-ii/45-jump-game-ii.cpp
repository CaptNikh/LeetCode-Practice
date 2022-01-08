class Solution {
public:
    int jumps(vector<int> &arr, int i, vector<int> &dp)
    {
        if(i >= arr.size() - 1)
            return 0;
        
        if(dp[i] != 100001)
            return dp[i];
        
        for(int j = 1; j <= arr[i]; j++)
        {
            dp[i] = min(dp[i], 1 + jumps(arr, i + j, dp));
        }
        
        return dp[i];
        
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 100001);
        return jumps(nums, 0, dp);
    }
};