class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n =  arr.size();
//         for(int i = 0; i < n; i++)
//         {
//             while(arr[i] != n && i != arr[i])
//             {
//                 swap(arr[i], arr[arr[i]]);
//             }
//         }
        
//         int ans = n;
//         for(int i = 0; i < n; i++)
//         {
//             if(i != arr[i])
//             {
//                 ans = i;
//                 break;
//             }
//         }
        
//         return ans;
//         using XOR operatot
        int i = 0, ans = 0;
        
        for(i = 0; i < n; i++)
        {
            ans = ans^i^arr[i];
        }
        
        return ans^i;
    }
};