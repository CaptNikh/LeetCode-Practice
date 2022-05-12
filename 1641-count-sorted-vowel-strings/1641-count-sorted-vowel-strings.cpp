class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> vowels(5, 1);
        
        
        for(int i = 2; i <= n; i++) {
            for(int i = 3; i >= 0; i--){
                vowels[i] += vowels[i + 1];
            }
        }
        
        int ans = accumulate(vowels.begin(), vowels.end(), 0);
        return ans;
    }
};