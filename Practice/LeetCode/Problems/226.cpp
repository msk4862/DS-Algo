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
//     using helper function
    
//     void invert(TreeNode* root) {
//         if(!root or (!root->left and !root->right)) return;
        
//         TreeNode* t = root->left;
//         root->left = root->right;
//         root->right = t;
        
//         invert(root->left);
//         invert(root->right);
    
//     }
    
    TreeNode* invertTree(TreeNode* root) {
        // invert(root);
        if(!root) return root; 
        
        TreeNode* t = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = t;
        
        return root;
    }
};
