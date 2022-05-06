class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefixMax(n, 0);
        vector<int> suffixMin(n, 0);
        
        prefixMax[0] = nums[0];
        suffixMin[n - 1] = nums[n - 1];
        
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(prefixMax[i - 1] < nums[i] and suffixMin[i + 1] > nums[i])
                ans += 2;
            
            else if(nums[i] > nums[i - 1] and nums[i] < nums[i + 1])
                ans += 1;
        }
        
        return ans;
    }
};