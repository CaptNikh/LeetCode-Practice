class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        stack<int> s;
        int l = nums.size(), r = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] > nums[i])
            {
                l = min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] < nums[i])
            {
                r = max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        
        return r - l > 0 ? r - l + 1 : 0;
        
        
        
    }
};