class Solution {
public:
    int robb(vector<int> &arr, int l, int r)
    {
        if(r - l == 1)
            return arr[l];
        
        int ans1 = arr[l];
        int ans2 = max(arr[l], arr[l + 1]);
        int ans = ans2;
        
        for(int i = l + 2; i < r; i++)
        {
            ans = max(ans2, ans1 + arr[i]);
            ans1 = ans2;
            ans2 = ans;
        }
        return ans;
            
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
    
        return max( robb(nums, 0 , n - 1), robb(nums, 1, n));
        
    }
};