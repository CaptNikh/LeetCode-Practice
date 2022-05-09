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
    int ht;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        ht =  1 + max(height(root->left), height(root->right));
        return ht;
    }
    
    int helper(TreeNode* root, int depth) {
        if(!root)
            return 0;
        if(depth == ht - 1)
            return root->val;
        
        return helper(root->left, depth + 1) + helper(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        height(root);
        return helper(root, 0);
    }
};