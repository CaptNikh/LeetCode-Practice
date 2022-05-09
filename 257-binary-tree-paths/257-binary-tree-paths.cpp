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
    
    void printPaths(TreeNode* root, string temp, vector<string> &ans){
        if(!root)
            return;
        temp += "->";
        temp += to_string(root->val);
        if(!root->left and !root->right)
            ans.push_back(temp);
        else {
            printPaths(root->left, temp, ans);
            printPaths(root->right, temp, ans);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        
        if(!root)
            return ans;
        
        string temp = to_string(root->val);
        
        if(!root->left and !root->right)
        {
            ans.push_back(temp);
            return ans;
        }
        
        printPaths(root->left, temp, ans);
        printPaths(root->right, temp, ans);
        
        return ans;
    }
};