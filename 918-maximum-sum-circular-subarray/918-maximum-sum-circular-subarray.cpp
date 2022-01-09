class Solution {
public:
    
    int normalSubarrayMax(vector<int> &nums)
    {
        int x = *max_element(nums.begin(), nums.end());
        if(x < 0)
            return x;
        int n = nums.size();
        int curr_max = 0;
        int maxSoFar = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr_max += nums[i];
            if(curr_max < 0)
                curr_max = 0;
            maxSoFar = max(maxSoFar, curr_max);
        }
        return maxSoFar;
    }
    int circularSubarrayMax(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = -1*nums[i];
        }
        
        
        return sum + normalSubarrayMax(nums);
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int x = normalSubarrayMax(nums);
        int y = circularSubarrayMax(nums);
        if(x < 0)
            return x;
        return max(x, y);
    }
};