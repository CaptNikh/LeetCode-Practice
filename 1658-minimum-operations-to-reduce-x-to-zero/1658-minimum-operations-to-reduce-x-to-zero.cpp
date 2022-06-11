class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sum -= x;
        if(sum == 0)
            return nums.size();
        
        int ans = 0, res = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            res += nums[j];
			
            while(i < nums.size() && res > sum) 
                res -= nums[i++];
				
            if(res == sum)  
                ans = max(ans ,j-i+1);
        }
        if(!ans) 
            return -1;
        
        return nums.size() - ans;
    }
    
};