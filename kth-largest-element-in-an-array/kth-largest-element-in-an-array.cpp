class Solution {
public:
    int partition(vector<int> &arr, int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;
        
           for(int j = l ; j <= r - 1; j++)
           {
               if(arr[j] < pivot)
               {
                   i++;
                   swap(arr[j], arr[i]);
               }
           }
           swap(arr[i + 1], arr[r]);
           return i + 1;
    }
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = 0, r = n - 1;
        k = n - k + 1;
        while(l <= r)
        {
            int p = partition(arr, l , r);
            if(p == k - 1)
            {
                return arr[p];
            }
            else if(p > k -1)
                r = p - 1;
            else
                l = p + 1;
        }
        return -1;
    }
};