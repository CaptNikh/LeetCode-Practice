class Solution {
public:
    bool checkInclusion(string t, string s) {
        vector<int> count1 (26, 0);
        vector<int> count2 (26, 0);

        int n = t.size();
        int m = s.size();
        if(n > m)
            return false;
        
        for (int i = 0; i < n; i++)
        {
            // freq map of t
            count1[t[i] - 'a']++;
            // freq map of 1st window of s
            count2[s[i] - 'a']++;
        }

        if (count1 == count2)
            return true;

        for (int i = n; i < m; i++)
        {
            count2[s[i] - 'a']++;
            count2[s[i - n] - 'a']--;

            if (count1 == count2)
                return true;
        }

        return false;
        }
};