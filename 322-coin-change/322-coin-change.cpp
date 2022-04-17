class Solution {
public:
    
    long mincoins(vector<int>&coins, int amount , vector<long>&ans)
    {
        
        if(amount < 0 ) return INT_MAX;
        if( amount == 0 )return 0;
        if( ans[amount] != -1) return ans[amount];
        int i;
        long res = INT_MAX;
        for(  i = 0; i < coins.size(); i++)
        {
            if(amount >= coins[i])
                res = min(res, 1 + mincoins(coins,amount-coins[i],ans));
           
        }
        return ans[amount] = res;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<long>ans(amount+1,-1);
        long res = mincoins(coins,amount,ans);
         if( res == INT_MAX)
             return -1;
        else
            return res;
    }
};