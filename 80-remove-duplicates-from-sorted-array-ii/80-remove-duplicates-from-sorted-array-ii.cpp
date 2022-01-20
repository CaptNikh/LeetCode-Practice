class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        
        if(n < 2)
            return n;
        
        int j = 1, i = 1;
        int cnt = 1;
        
        while(j < n)
        {
            if(arr[j] != arr[j - 1])
            {
                arr[i++] = arr[j];
                cnt = 1;
            }
            else
            {
                if(cnt < 2)
                {
                    cnt++;
                    arr[i++] = arr[j];
                }
            }
            j++;
        }
        return i;
    }
};