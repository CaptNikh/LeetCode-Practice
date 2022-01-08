class Solution {
public:
    int LCS(string &s, string &t, int i , int j,vector<vector<int>> &dp)
    {
        if(i == s.length() || j == t.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = 1 + LCS(s, t, i + 1, j + 1, dp);
        
        int x = LCS(s, t, i, j + 1, dp);
        int y = LCS(s, t, i + 1, j, dp);
        
        return dp[i][j] = max(x , y);
    }
    bool isSubsequence(string s, string t) {
//      we can do the LCS approach and if LCS == s.lenght then it is true
        int n = s.length(), m = t.length();
        
        vector<vector<int>> dp(n , vector<int> (m, -1));
       if(s.length() == LCS(s, t, 0 , 0, dp))
           return true;
        else
            return false;
    }
};