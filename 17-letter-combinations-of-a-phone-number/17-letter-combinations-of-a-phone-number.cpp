class Solution {
public:
    void printAllCombs(string nums, string temp, int i, vector<string> &arr, vector<string> & ans)
    {
	    if (i == nums.length()) {
            ans.push_back(temp);
            return;
	    }

        for (int j = 0; j < arr[nums[i] - '2'].size(); j++)
        {
            printAllCombs(nums, temp + arr[nums[i] - '2'][j], i + 1, arr, ans);
        }

    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        vector<string> arr = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        printAllCombs(digits, temp , 0, arr, ans);
        return ans;
    }
};