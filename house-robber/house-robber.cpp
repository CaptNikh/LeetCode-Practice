class Solution {
public:
//     int rob1(vector<int> &nums, int n, int i)
//     {
//         if(i >= n)
// 		return 0;

//         if(n == 0)
//             return 0;
//         if(n == 1)
//             return nums[0];

//         int ans1 = nums[i] + rob1(nums, n, i + 2);
//         i++;
//         if(i < n){
//         int ans2 = nums[i] + rob1(nums, n, i + 2);
//         return max(ans1, ans2);
//         }
//         return ans1;
        
//     }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
         if(n == 1)
            return nums[0];
        
        int dp[n];
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++)
        {
            dp[i] = nums[i];
            int x = 0;
            for(int j = 0; j <= i - 2; j++)
            {
                x = max(dp[j], x);
            }
            dp[i] += x;
        }
        
       
        return max(dp[n - 1], dp[n - 2]);
    }
};

















