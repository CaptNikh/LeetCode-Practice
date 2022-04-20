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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        
        if(root == NULL)
            return ans;
        map<int, vector<pair<int, int>>> mp;
        
        queue<pair<TreeNode*,pair<int, int>>> q;
        
        q.push({root, {0, 0}});
        
        while(!q.empty()){
           auto p = q.front();
           q.pop();
           TreeNode* curr = p.first;
           int hd = p.second.first;
           int vd = p.second.second; 
            
            
           mp[hd].push_back({curr->val, vd});
           if(curr->left != NULL)
               q.push({curr->left, {hd - 1, vd + 1}});
           if(curr->right != NULL)
               q.push({curr->right, {hd + 1, vd + 1}});         
        }
        
        for(auto &i : mp)
        {
            vector<pair<int, int>> sub_ans = i.second;
            
            sort(sub_ans.begin(), sub_ans.end(),
                 [&](pair<int, int> &a, pair<int, int> &b){
                     if(a.second != b.second)
                         return a.second < b.second;
                     else{
                         return a.first < b.first;
                     }
                 });
            
            vector<int> arr;
            for(auto &i : sub_ans)
                arr.push_back(i.first);
            
            ans.push_back(arr);
        }
        return ans;
    }
};