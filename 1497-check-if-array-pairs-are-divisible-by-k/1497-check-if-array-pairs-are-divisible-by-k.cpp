class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
//         replace all numbers with arr[i] % k
//         if one number has remainder r other should have remainder k - r
//         then only there sum will be divisible by k
//         
//         
        int n = arr.size();
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] < 0)
                arr[i] = ((arr[i] % k) + k) % k;
            else
                arr[i] = arr[i] % k;
        }
        
        map<int,int> s;
        
        for(int i : arr)
            s[i]++;
        
        bool ok = false;
        
        if(s[0] % 2 == 0)
            ok = true;
        
        for(int i = 1; i < k; i++)
        {
            if(s[i] != s[k-i])
                return false;
        }
        
        if(ok)
            return true;
        else
            return false;
        
    }
};