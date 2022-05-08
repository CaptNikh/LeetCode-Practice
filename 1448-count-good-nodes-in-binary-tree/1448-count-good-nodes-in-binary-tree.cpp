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
    int goodNodes2(TreeNode* root, int prevMax) {
        if(root == NULL)
            return 0;
        
        if(root->val >= prevMax) { 
            return 1 + goodNodes2(root->left, root->val) + goodNodes2(root->right, root->val);
        }
        
        return goodNodes2(root->left, prevMax) + goodNodes2(root->right, prevMax);
    }
    
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        return goodNodes2(root, INT_MIN);
            
    }
};