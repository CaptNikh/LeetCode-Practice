class Solution {
public:
    int dp[601][101][101];
    
    int recurse(vector<string> &strs, int i, int m, int n) {
        if(i >= strs.size() || m < 0 || n < 0 || m + n == 0)
            return 0;
       
        
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        
        
        int cntz = 0;
        string s = strs[i];
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '0')
                cntz++;
        }
        
        int cnto = s.size() - cntz;
        
        if(m >= cntz and n >= cnto)
            return dp[i][m][n] = max(1 + recurse(strs, i+1, m-cntz, n-cnto), recurse(strs,i+1,m,n));
        
        return dp[i][m][n] = recurse(strs, i+1, m, n);
        
        
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        
        
        return recurse(strs, 0, m, n);
    }
};