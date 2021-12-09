class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> v(n);
        int ind = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] % 2 == 0){
                swap(arr[ind], arr[i]);
                ind++;
            }
        }
        
        int odd_ind;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] % 2 == 1){
                odd_ind = i;
                break;
            }
        }
        
        int i = 0, j = odd_ind;
        int k = 0;
        while(i < odd_ind and j < n)
        {
            v[k++] = arr[i++];
            v[k++] = arr[j++];
        }
        while(i < odd_ind)
        {
            v[k++] = arr[i++];
        }
        while(j < n)
        {
            v[k++] = arr[j++];
        }
        return v;
    }
};