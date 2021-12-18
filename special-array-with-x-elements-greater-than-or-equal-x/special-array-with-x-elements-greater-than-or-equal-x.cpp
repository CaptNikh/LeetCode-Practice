class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = -1;
        
        int r = nums[n -1];
        
        for(int i = 0; i <= r; i++)
        {
            if(lower_bound(nums.begin(), nums.end(), i) - nums.begin() < n){
            int j = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
            
            if(n - j == i)
                ans = i;
            }
            
            if(i <= nums[0])
            {
                if(i == n)
                    ans = i;
            }
        }
        
        return ans;
        
    }
};