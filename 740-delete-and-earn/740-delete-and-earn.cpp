class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxe = *max_element(nums.begin(), nums.end());
        
        vector<int> freq (20005, 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        
        int dp[20005];
        
        dp[0] = 0;
        dp[1] = freq[1];
        
        for(int i = 2; i <= maxe; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + freq[i] * i);
        }
        
        return dp[maxe];
        
    }
};