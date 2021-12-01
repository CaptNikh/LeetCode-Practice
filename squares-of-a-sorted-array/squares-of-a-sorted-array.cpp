class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector <int> arr;
        int i = 0;
        int n = nums.size();
        while(i  < n && nums[i] < 0)
        {
            arr.push_back(abs(nums[i++]));
        }
        
        reverse(arr.begin(), arr.end());
        
        
        
        vector <int> arr1(n);
        int m = arr.size();
        int j = 0;
        int k = 0;
        while(i < n and j < m)
        {
            if(nums[i] < arr[j]){
                arr1[k++] = nums[i++];
            }
            else
            {
                arr1[k++] = arr[j++];
            }
        }
        while(i < n)
            arr1[k++] = nums[i++];
        while(j < m)
            arr1[k++] = arr[j++];
        
        
        for(int &i : arr1)
            i = i*i;
        
        return arr1;
        
    }
};