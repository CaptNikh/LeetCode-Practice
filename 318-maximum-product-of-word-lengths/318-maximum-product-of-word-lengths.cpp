class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> arr;
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            
            vector<int> freq(26, 0);
            
            for(int j = 0; j < words[i].size(); j++) {
                freq[words[i][j] - 'a']++;
            }
            for(auto &temp : arr) {
                bool ok = true;
                int sz = 0;
                for(int k = 0; k < 26; k++){
                    if(temp[k] != 0 && freq[k] != 0)
                        ok = false;
                    sz += temp[k];
                }
                
                if(ok) {
                    ans = max(ans, (int)words[i].size() * sz);
                }
            }
            
            arr.push_back(freq);
        }
        
        return ans;
    }
};