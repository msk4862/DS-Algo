/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* r, int l, int h) {
        
        if(l<=r->val and r->val<=h) return r;
        // searching larger values
        else if(r->val<l) return lca(r->right, l,h);
        // searvhing smaller values
        return lca(r->left, l,h);

    }    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        int l,h;
        if(p->val < q->val) {
            l=p->val;
            h=q->val;
        } else {
            l=q->val;
            h=p->val;
        }
        
        return lca(root, l, h);
    }
};