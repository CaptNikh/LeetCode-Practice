class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, k = n - 1;
        vector<int> arr(n);
        while(l <= r)
        {
            if(abs(nums[l]) > abs(nums[r]))
            {
                arr[k--] = nums[l] * nums[l++];
            }
            else{
                arr[k--] = nums[r] * nums[r--];
            }
        }
        
        return arr;
    }
};