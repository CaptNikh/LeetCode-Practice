class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int j = -1;
        if(n == 1)
            return 1;
        for(int i = 0; i < n  - 1; i++)
        {
            int cnt = 0;
            cnt++;
            j++;
            arr[j] = arr[i];
            
            while(i < n - 1 && arr[i] == arr[i + 1])
            {
                cnt++;       
                if(cnt <= 2)
                {
                    j++;
                    arr[j] = arr[i];
                    
                }
                i++;
            }
        }
        
        if(n >= 2 && arr[n - 1] != arr[n - 2])
        {
            j++;
            arr[j] = arr[n - 1];
            
        }
        
        return j + 1;     
    }
};