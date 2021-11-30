class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        // In c++ we can use
        // next_permutation(nums.begin(), nums.end());
    
//         step 1 -> Find the first index with arr[i] < arr[i] + 1;
        int index = -1;
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--)
        {
            if(arr[i]  < arr[i + 1])
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            reverse(arr.begin(), arr.end());
                return;
        }
            
        
        for(int i = n - 1; i >= 0; i--)
        {
            if(arr[i] > arr[index])
            {
                swap(arr[i], arr[index]);
                break;
            }
        }
        reverse(arr.begin() + index + 1, arr.end());
        return;
    }
};