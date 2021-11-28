class Solution {
public:
    int countPairs(vector<int>& nums, int k, int mid)
    {
        int n =  nums.size();
        int total = 0;
        int j = 1;
        
        for(int i = 0; i < n; i++)
        {
            while(j < n && nums[j] - nums[i] <= mid)
                j++;
            j--;
            
            total += j - i;
            
        }
        return total;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n =  nums.size();
        int diff = nums[n - 1] - nums[0];
        
        int low = 0, high = diff;
        while(low  < high)
        {
            int mid = low + (high - low)/2;
            
            if(countPairs(nums, k, mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};