class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int x3 =  INT_MIN;
        stack<int> s;      // x1 < x3 < x2
        
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < x3)
                return true;
            else {
                while(!s.empty() && nums[i] > s.top())
                {
                    x3 = s.top();
                    s.pop();
                }
            }
            s.push(nums[i]);
        }         
        
        return false;
    }
};