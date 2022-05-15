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
    pair<int, int> maxSumPath(TreeNode* root){
        if(!root)
            return {INT_MIN, INT_MIN};
        
        pair<int, int> lst = maxSumPath(root->left);
        pair<int, int> rst = maxSumPath(root->right);
        
        int max_sum_path = max({root->val + max(0, lst.second) + max(0, rst.second), lst.first,                                rst.first});
        
        int max_uniPath = root->val + max({lst.second, rst.second, 0});
        
        return {max_sum_path, max_uniPath};
    }
    int maxPathSum(TreeNode* root) {
        pair<int, int> p = maxSumPath(root);
        return p.first;
    }
};