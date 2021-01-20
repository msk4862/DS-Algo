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
    bool isSymmetricHelper(TreeNode* leftRoot, TreeNode* rightRoot) {
        if(!leftRoot && !rightRoot) return true;
        if(!leftRoot || !rightRoot) return false;
        
        // like equal tree with going in opposite direction 
        return leftRoot->val==rightRoot->val && isSymmetricHelper(leftRoot->left, rightRoot->right) && isSymmetricHelper(leftRoot->right, rightRoot->left);
    }    
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return isSymmetricHelper(root->left, root->right);   
    }
};
