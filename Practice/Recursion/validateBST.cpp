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
    
    bool helper_isValidBST(TreeNode* root, long upper_limit, long lower_limit) {
        if(root==nullptr ) {
            return true;
        }
        long val = root->val;
                    // cout<<"tri "<<val<<lower_limit<<endl;
        if(val >= upper_limit ) return false;
        if(val <= lower_limit) return false;
        // cout<<"sdsd";
        return helper_isValidBST(root->left, val, lower_limit) and helper_isValidBST(root->right, upper_limit, val);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper_isValidBST(root, LONG_MAX, LONG_MIN);
    }
};