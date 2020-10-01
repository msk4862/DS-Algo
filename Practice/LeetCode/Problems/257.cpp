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
    void dfs(TreeNode* r,string cur, vector<string>& res) {
        if(!r->left and !r->right) {
            cur += to_string(r->val);
            res.push_back(cur);
            return;
        }
        cur += to_string(r->val)+"->";
        if(r->left) dfs(r->left, cur, res);
        if(r->right) dfs(r->right, cur, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        
        dfs(root, "", res);
        return res;
    }
};