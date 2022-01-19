class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        
        arr[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1] + nums[i];
        }
        
        int ans = INT_MAX;
        for(int i = n - 1; i >= 0 and arr[i] >= target; i--)
        {
            int j = upper_bound(arr.begin(), arr.end(), arr[i] - target) - arr.begin();
            
            ans = min(ans, i - j + 1);
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};