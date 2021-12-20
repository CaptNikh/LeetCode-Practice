class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int sol = 0;
        int n = nums.size();
        for(int i = 0 ; i < n; i++)
        {
            int x = target - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r)
            {
                int sum = nums[l] + nums[r];
                
                if(sum == x)
                    return target;
                
                else if(sum < x)
                {
                    int dif = abs(target - (nums[i] + sum));
                    if(dif < ans){
                        sol = nums[i] + sum;
                        ans = dif;
                    }
                    l++;
                }
                else if(sum > x)
                {
                    int dif = abs(target - (nums[i] + sum));
                    if(dif < ans){
                        sol = nums[i] + sum;
                        ans = dif;
                     }
                    r--;
                }
            }
        }
        
        return sol;
        
    }
};