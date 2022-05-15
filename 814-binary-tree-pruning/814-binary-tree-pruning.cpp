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
    int pruneTreeHelper (TreeNode* root) {
        if(!root)
            return NULL;
        
        int x = pruneTreeHelper(root->left), y = pruneTreeHelper(root->right);
        if(x == 0)
           root->left = NULL;
        if(y == 0)
           root->right = NULL;
        
        return (root->val || x || y);
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        pruneTreeHelper(root);
        if(root->val == 0 && !root->left && !root->right)
            return NULL;
        return root;
        
    }
};