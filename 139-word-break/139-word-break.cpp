class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
//         we are going to do the bottom up approach starting from the end
//         [a b c d e f g h] if a word starting from an  index i is found in the dictionary we check if the word starting 
//         i + words size is already present for the answer to be true ro not
//        if(word found) and dp[i + w] = true;
//             then only dp[i] is true;
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true; // this is our base case
        
        
        for(int i = n - 1; i >= 0; i--)
        {
            for(int k = 0; k <= n - i + 1; k++){
                string ans = s.substr(i, k);
                bool ok = false;
                for(auto j : wordDict)
                {
                    if(j == ans and dp[i + j.size()] == true)
                    {
                        dp[i] = true;
                        ok = true;
                        break;

                    }
                }
                
                if(ok)
                    break;
            }   
        }
        
        if(dp[0])
            return true;
        else return false;
    }
};