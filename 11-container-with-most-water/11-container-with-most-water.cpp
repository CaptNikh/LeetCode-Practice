class Solution {
public:
    int maxArea(vector<int>& arr) {
        
        
        int i = 0, j = arr.size() - 1;
        int ans = min(arr[i], arr[j]) * (j - i);
        while(i < j)
        {
            if(arr[i] < arr[j])
                i++;
            else if(arr[i] > arr[j])
                j--;
            else
                i++,j--;
            
            ans = max(ans, min(arr[i],arr[j])*(j -i));
        }
        
        return ans;
    }
};