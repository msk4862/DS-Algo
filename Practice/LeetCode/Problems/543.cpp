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
    int d=0;
    
    int maxHeight(TreeNode* r) {
        if(!r) return 0;
        if(!r->left and !r->right) return 1;
        
        int l,ri;
        l = maxHeight(r->left);
        ri = maxHeight(r->right);
        
        d = max(l+ri+1, d);
        
        return max(l, ri)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxHeight(root);
        
        if(d>1)
        return d-1;
        return d;
    }
};
