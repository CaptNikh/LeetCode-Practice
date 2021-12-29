class Solution {
public:
    long long merge(vector<int> &arr, int l ,int m, int r)
    {
        long long res = 0;
        int n1 = m - l + 1;
        int n2 = r - m;
        
        long long left[n1], right[n2];
        
        for(int i = 0 ; i < n1; i++)
        {
            left[i] = arr[i + l];
        }
        for(int i = 0; i < n2; i++)
        {
            right[i] = arr[m + 1 + i];
        }
        
        int i = 0, j = 0, k = l;
        // Counting the no of pairs

        while(i < n1 and j < n2)
        {
            if(left[i] > 2*right[j])
            {
                j++;
            }
            else
            {
                i++;
                res += j;
            }
        }
        while(i < n1)
        {
            i++;
            res += j;
        }
        
       // Merge operation
        i = 0, j = 0;
        while(i < n1 and j < n2)
        {
            if(left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else{
                 arr[k] = right[j];
                 j++;
            }
            k++;
        }
        while(i < n1){arr[k++] = left[i++];};
        while(j < n2){arr[k++] = right[j++];};
        
        return res;
    }
    long long revPairs(vector<int> &arr, int l, int r)
    {
        long long res = 0;
        
        if(l < r)
        {
            int m = l + (r - l) / 2;
            res += revPairs(arr, l, m);
            res += revPairs(arr, m + 1, r);
            res += merge(arr, l, m, r);
        }
        return res;          
    }
    int reversePairs(vector<int>& nums) {
        return revPairs(nums, 0, nums.size() - 1);
    }
};