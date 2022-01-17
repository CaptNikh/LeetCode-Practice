class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n =  nums.size();
        if(n < 3)
            return 0;
        int ans = 0;
        
        vector<int> arr(n + 1, 0);
        arr[3] = 1;
        
        for(int i = 4; i <= n; i++)
        {
            arr[i] = arr[i - 1] + i - 3 + 1;
        }
        for(int i = 1; i < n; i++)
        {
            int cnt = 0;
            while(i < n - 1 && (nums[i] - nums[i - 1]) == (nums[i + 1] - nums[i]))
            {
                i++;
                cnt++;
            }
            if(cnt != 0)
            ans += arr[cnt + 2];    
        }
        return ans;
    }
};