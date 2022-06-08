class Solution {
public:
    
    bool isPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high) {
            if(s[low] == s[high]){
                low++;high--;
            }
            else
                return false;              
        }
        return true;
    }
    int removePalindromeSub(string s) {
        
        if(s.size() == 0)
            return 0;
        if(isPalindrome(s))
            return 1;
        else // one subsequence contains and the other contains b only.
            return 2;
    }
    
    
};