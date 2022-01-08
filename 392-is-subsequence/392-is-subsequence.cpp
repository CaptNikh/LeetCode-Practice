class Solution {
public:
    bool isSubsequence(string s, string t) {
//      we can do the LCS approach and if LCS == s.lenght then it is true
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        
        while(i < n && j < m)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if(i == n)
            return true;
        else
            return false;
    }
};