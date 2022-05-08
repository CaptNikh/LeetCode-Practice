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
    bool areMirrorImg(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        
        return r1-> val == r2->val && areMirrorImg(r1->left, r2->right) && areMirrorImg(r1->right, r2->left);
    }
    bool isSymmetric(TreeNode* root) {
       if(!root)
           return true;
        
        return areMirrorImg(root->left, root->right);
    }
};