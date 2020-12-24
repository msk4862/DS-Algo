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
    
    void calcSum(TreeNode* root, int sum, vector<vector<int>> &res, int curSum = 0, vector<int> curPath={}) {
        if(!root) return;
        
        if(!root->left && !root->right && curSum + root->val == sum) {
            curPath.push_back(root->val);
            res.push_back(curPath);
        }
        
        curSum += root->val;
        curPath.push_back(root->val);
        
        calcSum(root->left, sum, res, curSum, curPath);
        calcSum(root->right, sum, res, curSum, curPath);
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        calcSum(root, sum, res);
        
        return res;
    }
};
