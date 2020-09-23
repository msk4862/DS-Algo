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
    void update(TreeNode* r, int& sum) {
        if(!r) return;
        
        update(r->right, sum);
        sum+=r->val;
        r->val=sum;
        update(r->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        int t=0;
        update(root, t);
        return root;
    }
};