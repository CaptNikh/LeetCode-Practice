class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(nums1.begin(), nums1.end());
        int n = nums2.size();
        for(int i = 0; i < n ; i++)
        {
            auto it = s.upper_bound(nums2[i]);
            
            if(it == s.end())
                it = s.begin();
            
            nums1[i] = *it;
            
            s.erase(it);            
        }
        
        return nums1;
    }
};