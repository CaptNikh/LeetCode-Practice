class Solution {
public:
    bool canJump1(vector<int> &arr, int i, vector<int> &dp)
    {
        if(i >= arr.size() - 1)
            return true;
        if(arr[i] == 0)
            return false;
        if(dp[i] != -1)
            return dp[i];
        bool ans = false;
        for(int j = arr[i]; j >= 1; j--)
        {
            ans |=  canJump1(arr, i + j, dp);
            if(ans == true)
                break;
        }
        if(ans)
            dp[i] = 1;
        else
            dp[i] = 0;
        return ans;
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        vector<int>dp(nums.size() , -1);
        return canJump1(nums, 0, dp);
    }
};