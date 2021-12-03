class Solution {
public:
    long long thirdMax(vector<int>& nums) {
        
          long long max1 = LLONG_MIN;
          long long max2 = LLONG_MIN;
          long long max3 = LLONG_MIN;
        
        for(auto i : nums)
        {
            if(i == max1 or i == max2 or i == max3)
                continue;
            else if (max1 == LLONG_MIN || i > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if(max2 == LLONG_MIN || i > max2)
            {
                max3 = max2;
                max2 = i;
            }
            else if(max3 == LLONG_MIN || i > max3)
            {
                max3 = i;
            }
        }
        return max3 == LLONG_MIN ? max1 : max3;
    }
};