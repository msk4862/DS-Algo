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
    int tilt = 0;
    
    int fsum(TreeNode* r) {
        if(!r) return 0;
        if(!r->left and !r->right) return r->val;
        
        int l=0,ri=0;
        
        l = fsum(r->left); 
        ri = fsum(r->right);
        
        tilt+=abs(l-ri);
        
        return l+ri+r->val;
        
    }
        
    int findTilt(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return 0;
        fsum(root);
        
        return tilt;
    }
};