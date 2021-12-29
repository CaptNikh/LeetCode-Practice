class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int, int> s;
        for(int i = 0; i < arr2.size(); i++)
        {
            s[arr2[i]] = i;
        }
        vector<int> ans = arr1;
        sort(ans.begin(), ans.end(), [&](int a, int b){
            
            if(s.find(a) != s.end() && s.find(b) != s.end())
               return s[a] < s[b];
            else if(s.find(a) != s.end() && s.find(b) == s.end())
               return true;
            else if(s.find(a) == s.end() && s.find(b) != s.end())
                return false;
            else
                return a < b;
            
        });
        return ans;
    }
};