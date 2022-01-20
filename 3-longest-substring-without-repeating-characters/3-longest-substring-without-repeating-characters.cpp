class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> mp;
        // using sliding window
        // until the condn is valid we extend the window
        // else move the start pointer until the condn is valid again
        
        int j = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            
            while(mp[s[i]] > 1)
            {
                mp[s[j]]--;
                j++;
            }
            
             ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};