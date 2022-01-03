class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans1 = nums[0];
        if(n == 1)
            return nums[0];
        int ans2 = max(nums[0], nums[1]);
        
        int ans = ans2;
        for(int i = 2; i < n; i++)
        {
            ans = max(ans2, ans1 + nums[i]);
            ans1 = ans2;
            ans2 = ans;
        }
        return ans;
    }
};