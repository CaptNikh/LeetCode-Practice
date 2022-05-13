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
    unordered_map<TreeNode*, int> mp;
    
    int height(TreeNode* root) {
        if(!root)
            return mp[root] = 0;
        
        mp[root] = 1 + max(height(root->left), height(root->right));
        return mp[root];
    }
    int helper(TreeNode* root) {
        // either contained entirely in left or entirely in right we know that
        
        if(!root)
            return 0;
        
        int d1 = mp[root->left] + mp[root->right];
        int d2 = helper(root->left);
        int d3 = helper(root->right);
        
        return max({d1, d2, d3});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return helper(root);
    }
};