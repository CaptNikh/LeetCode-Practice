class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n =  arr.size();
        for(int i = n - 2; i >= 1; i--)
        {
            if(arr[i+1] < arr[i] + arr[i - 1])
            {
                return arr[i + 1] + arr[i] + arr[i - 1];
            }
        }
        return 0;
    }
};