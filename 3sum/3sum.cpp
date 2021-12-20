class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            int target = -1 * nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            if(target < 0)
                break; // due to sorting we cant find smaller numbers ahead of this number.
            while(front < back)
            {
                int sum = nums[front] + nums[back];
                
                if(sum < target)
                    front++;
                else if(sum > target)
                    back--;
                else{
                    
                    vector<int> ans = {nums[i], nums[front], nums[back]};
                    res.push_back(ans);
                    // processing duplicates of 2nd number;
                    // rolling the front pointer to the next different number.
                    while(front < back && ans[1] == nums[front])
                        front++;
                    
                    
                    //processing the 3rd duplicate number
//                      rolling the back pointer to the previous different number
                    while(front < back && ans[2] == nums[back])
                        back--;
                }
                
//                 processing the first duplicate number
                while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }
        }
        
        return res;
    }
};