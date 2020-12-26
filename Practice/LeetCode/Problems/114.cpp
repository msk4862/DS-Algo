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
    
    TreeNode* flattenH(TreeNode* root) {
        if(!root) return nullptr;
        
        TreeNode* orgRight = root->right;
        root->right = flattenH(root->left);
        
        TreeNode* r = root;
        while(r->right) {
            r = r->right;
        }
        r->right = flattenH(orgRight);
        
        root->left = nullptr;
        return root;
    }
        
    void flatten(TreeNode* root) {
        flattenH(root);
    }
};
