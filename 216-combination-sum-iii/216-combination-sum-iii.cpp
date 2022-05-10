class Solution {
public:
     
    
    void backtrack(vector<int>& temp, int x, int k, int n, vector<vector<int>> &ans) {
        if(n < 0 or temp.size() > k)
            return;
        if(n == 0 and temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = x; i <= 9; i++) {
            temp.push_back(i);
            backtrack(temp, i + 1, k, n - i, ans);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(temp, 1, k, n, ans);
        return ans;
    }
};