class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefixMin(n, 0);
        vector<int> prefixMax(n, 0);
        
        prefixMin[0] = nums[0];
        prefixMax[n - 1] = nums[n - 1];
        
        for(int i = 1; i < n; i++) {
            prefixMin[i] = min(nums[i], prefixMin[i - 1]);
        }
        
        for(int i = n - 2; i >= 0; i--) {
            prefixMax[i] = max(nums[i], prefixMax[i + 1]);
        }
        
        
        for(int i = 1; i < n - 1; i++) {
            if(prefixMax[i] > nums[i] and prefixMin[i] < nums[i])
                return true;
        }
        
        return false;
        
    }
};