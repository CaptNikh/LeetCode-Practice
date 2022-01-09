class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n = nums.size();
        
        int x = *max_element(nums.begin(), nums.end());
        if(x < 0)
            return x;                             
        int curr_sum = 0; 
        int maxSoFar = 0;
        
        for(int i = 0; i < n; i++)
         {
            curr_sum += nums[i];
             
             if(curr_sum < 0)
                 curr_sum = 0;
             
             maxSoFar = max(maxSoFar, curr_sum);
         }
        return maxSoFar;
        
    }
};