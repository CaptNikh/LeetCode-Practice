class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        for(auto i : nums)
        {
            mp[i]++;
        }
        
        vector<pair<int,int>> arr;
        
        for(auto it : mp)
        {
            arr.push_back({it.first, it.second});
        }
        
        sort(arr.begin(), arr.end(), [&](pair<int, int> a, pair<int, int> b){
           if(a.second == b.second)
               return b.first < a.first;
            
            return a.second < b.second;
        });
        
        
        vector<int> ans;
        
        for(auto i : arr)
        {
            while(i.second--)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};