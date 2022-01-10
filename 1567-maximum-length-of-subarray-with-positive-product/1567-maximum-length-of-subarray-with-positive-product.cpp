class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        
        // maintaining 2 arrays for maxlength of positve prodeuct and max length of
        // negative product
        
        // pos[i] = maximum subarray length with positive product including nums[i] so far
        // neg[i] = maximum subarray length with negative product including nums[i] so far
        int n = nums.size();
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        
        if(nums[0] > 0){
            pos[0] = 1;
            neg[0] = 0;
        }
        else if(nums[0] < 0)
        {
            pos[0] = 0;
            neg[0] = 1;
        }
        
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] < 0)
            {
                pos[i] = (neg[i - 1] > 0) ? neg[i - 1] + 1 : 0;
                neg[i] = (pos[i - 1] > 0) ? pos[i - 1] + 1 : 1;
            }
            else if(nums[i] > 0)
            {
                pos[i] = pos[i - 1] + 1;
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
            }
        }
        
        return *max_element(pos.begin(), pos.end());
        
    }
};