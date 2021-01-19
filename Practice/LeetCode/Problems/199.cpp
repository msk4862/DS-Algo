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
    void dfs(TreeNode* root, vector<int> &res, int depth = 0) {
        if(!root) return;
        
        if(res.size() <= depth) res.push_back(root->val);
        
        // travesing right most children first 
        // of every depth level
        dfs(root->right, res, depth+1);
        dfs(root->left, res, depth+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        dfs(root, res);
        return res;
    }
};
