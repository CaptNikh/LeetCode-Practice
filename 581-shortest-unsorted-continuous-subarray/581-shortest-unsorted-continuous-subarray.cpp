class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        
        bool sorted = true;
        int n = arr.size();
        int l = n;
        int r = 0;
        
        int minInc = INT_MAX;
        int maxInc = INT_MIN;
        
        for(int i = 1; i < n ; i++) {
            if(arr[i] < arr[i - 1])
                sorted = false;
            
            if(!sorted)
                minInc = min(minInc, arr[i]);
        }
        
        sorted = true;
        
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1])
                sorted = false;
            if(!sorted)
                maxInc = max(maxInc, arr[i]);
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > minInc)
            {
                l = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(arr[i] < maxInc){
                r = i;
                break;
            }
        }
        // cout << l;
        return r - l > 0 ? r - l + 1 : 0;
    }
};