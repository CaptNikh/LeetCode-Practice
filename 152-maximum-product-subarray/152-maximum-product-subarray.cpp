class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int curr_max = 1, curr_min = 1;
        int res = *max_element(arr.begin(), arr.end());
        
        // curr_min and curr_max store the max product till ith element and min prodeuct            till ith element 
        
        for(int i = 0; i < n; i++)
        {
            int temp = curr_max * arr[i];
            curr_max = max(max(arr[i]*curr_max, arr[i]*curr_min), arr[i]);
            curr_min = min(min(temp, curr_min * arr[i]), arr[i]);
            
            res = max(res, curr_max);
        }
        return res;
        
    }
};