class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       
        map<int, int> mp;
        int j = 0;
        int subArr = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            mp[nums[i]]++;
            subArr += nums[i];
            while(mp[nums[i]] > 1){
                mp[nums[j]]--;
                subArr -= nums[j++];
            }
            ans = max(subArr, ans);   
        }
        return ans;
    }
};