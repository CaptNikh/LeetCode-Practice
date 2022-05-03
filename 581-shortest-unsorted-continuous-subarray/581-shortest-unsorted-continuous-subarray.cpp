class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int j = nums.size() - 1;
        int i = 0;
        
        while(i <= j) {
            if(nums[j] == temp[j])
                j--;
            else if(temp[i] == nums[i])
                i++;
            else
                break;
        }
        
        return j - i + 1;
    }
};