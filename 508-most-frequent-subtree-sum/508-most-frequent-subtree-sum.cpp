/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    map<int, int> mp;
    
    int subTreeSum(TreeNode* root) {
        if(!root)
            return 0;
        
        int ls = subTreeSum(root->left);
        int rs = subTreeSum(root->right);
        
        int sum = ls + rs + root->val;
        
        mp[sum]++;
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        subTreeSum(root);
        
        
        vector<pair<int, int>> ans;
        for(auto &it : mp){
            ans.push_back({it.first, it.second});
        }
        
        sort(ans.begin(), ans.end(), [&](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });
        
        vector<int> res;
        res.push_back(ans[0].first);
        
        for(int i = 1; i < ans.size(); i++){
            if(ans[0].second == ans[i].second)
                res.push_back(ans[i].first);
            else
                break;
        }
        
        return res;
    }
};