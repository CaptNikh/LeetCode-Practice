class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        // we need to maximise arr[j] - j and arr[i] - i for i < j 
        int maxAF = arr[n - 1] - (n - 1);
        int ans = 0;
        for(int i = n - 2; i >= 0; i--)
        {
            maxAF = max(maxAF, arr[i + 1] - (i + 1));
            ans = max(arr[i] + i + maxAF, ans);
        }
        
        // for(int i = 0; i < n - 1; i++)
        // {
        //     ans = max(arr[i] + i + dp[i + 1], ans);
        // }
        return ans;
    }
};
// int curr_max = arr[0];
//         int ans = 0;
//         for(int i = 1; i < n; i++)
//         {
//             curr_max--;
//             ans = max(ans, curr_max + arr[i]);
            
//             if(curr_max <= arr[i]){
//                 curr_max = arr[i];
//             }
//         }
//         return ans;