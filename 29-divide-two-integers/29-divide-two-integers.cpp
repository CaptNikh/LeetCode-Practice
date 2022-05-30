class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if (divisor == 1 || dividend == 0) return dividend;
        
        if(divisor == 0)
            return INT_MAX;
        
        if (divisor == INT_MIN) {
            if (dividend == INT_MIN) return 1;
            else
                return 0;
        }

        if (dividend == INT_MIN) {
            if (divisor==1) return dividend;
            else if (divisor==-1) return INT_MAX;
            else 
                return (((divisor&1)==1) ? divide(dividend+1,divisor):divide(dividend>>1,divisor>>1));
        }

        
        int sign = divisor > 0 ^ dividend > 0 ? -1 : 1;
        
       int divd = abs(dividend), divs = abs(divisor), ans = 0;
        
        while(divd >= divs)
        {
            int temp = divs, sub_ans = 1;
            while(temp << 1 >= 0 && temp << 1 <= divd)
            {
                temp <<= 1;
                sub_ans <<= 1;
            }
            
            divd = divd - temp;
            ans += sub_ans;
        }    
        
        return sign*ans;
    }  
};