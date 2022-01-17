class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> arr(n + 1, 0);
        arr[0] = 0;
        
        if(n == 0)
            return arr;
        arr[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            arr[i] = arr[i / 2];
            
            if(i % 2 == 1)
                arr[i]++;
        }
        
        return arr;
    }
};