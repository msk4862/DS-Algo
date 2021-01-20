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
    // nodes values are in 0-9 range
    int sumNumbersHelper(TreeNode* root, int number = 0) {
        if(!root) return 0;
        
        if(!root->left && !root->right) return number*10 + root->val;
        
        return sumNumbersHelper(root->left, number*10 + root->val) + sumNumbersHelper(root->right, number*10 + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        return sumNumbersHelper(root);
    }
};
