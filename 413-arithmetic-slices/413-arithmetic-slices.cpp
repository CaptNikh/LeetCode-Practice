class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n =  nums.size();
        if(n < 3)
            return 0;
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            int cnt = 0;
            while(i < n - 1 && (nums[i] - nums[i - 1]) == (nums[i + 1] - nums[i]))
            {
                i++;
                cnt++;
            }
            if(cnt != 0)
            for(int j = 3; j <= cnt + 2; j++)
            {
                ans += (cnt + 2) - j + 1; 
            }    
        }
        return ans;
    }
};