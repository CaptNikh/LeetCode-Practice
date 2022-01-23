#include<bits/stdc++.h>
class Solution {
public:
    void numSubsets(vector<vector<int>> &arr1,vector<int> arr,vector<int>& nums,int i)
    {
        if(i==nums.size())
        {
            arr1.push_back(arr);
            return;
        }
        numSubsets(arr1,arr,nums,i+1);
        arr.push_back(nums[i]);
        numSubsets(arr1,arr,nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<vector<int>> arr1;
        vector<int> arr={};
        numSubsets(arr1,arr,nums,i);
        sort(arr1.begin(),arr1.end());
        return arr1;
    }
    
};