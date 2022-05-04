class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int count = 0;
        int n = nums.size();
        multiset<int> s;        
        
        for(int i = 0; i < n; i++) {
            
            auto it = s.find(k - nums[i]);
            
            if(it != s.end()) {
                count++;
                s.erase(it);
            }
            else
            {
                s.insert(nums[i]);
            }
        }
        
        return count;
    }
};