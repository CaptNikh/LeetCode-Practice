class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) {
        int n = arr.size();
        int curr_max = arr[0];
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            curr_max--;
            ans = max(ans, curr_max + arr[i]);
            
            if(curr_max <= arr[i]){
                curr_max = arr[i];
            }
        }
        return ans;
    }
};