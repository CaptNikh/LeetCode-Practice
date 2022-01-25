class Solution {
public:
    int dp[1005][1005];
    int lcs(string &s1, string &s2, int i, int j)
    {
        if(i == s1.length() or j == s2.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s1[i] == s2[j])
        {
            return dp[i][j] = 1 + lcs(s1, s2, i+1, j+1);
        }
        else
        {
            int x = lcs(s1, s2, i, j + 1);
            int y = lcs(s1, s2, i + 1, j);
            return dp[i][j] = max(x, y);
        }
            
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));        
        return lcs(s1, s2, 0, 0);
    }
};