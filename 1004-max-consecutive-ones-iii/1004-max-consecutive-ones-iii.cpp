class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        
        
        
//         We will move forward until the condn is true -> count of zeroes in the window is less than k
//         else we will move the start pointer forward until the condn becomes true;
        
        int n = arr.size();
        int start = -1;
        int cnt = 0;
        int ans = 0;
        int i = 0;
        while(i < n)
        {
            if(arr[i] == 0)
                cnt++;
            
            while(cnt > k and start < n)
            {
                start++;
                if(arr[start] == 0)
                    cnt--;
            }
            
            ans = max(ans, i - start);
            i++;

        }         
        return ans;
    }
};