class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            while(arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] != i + 1)
                ans.push_back(i + 1);
        }
        
        return ans;
    }
};