class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int> &a,  vector<int> &b){
            return a[0] < b[0] || a[0] == b[0] && a[1] > b[1];
        });
        
        vector<int> dp;
        for(auto &temp : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), temp[1]);
            if(it == dp.end())
                dp.push_back(temp[1]);
            else if(*it > temp[1])
                *it = temp[1];
        }
        
        return dp.size();
    }
};