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
    TreeNode* buildBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        if(root->val < val) root->right = buildBST(root->right, val);
        else root->left = buildBST(root->left, val);
        
        return root;
    }

    int ind = 1;
    void buildBSTOPT(vector<int> pre, TreeNode* root, int minE = INT_MIN, int maxE = INT_MAX) {
        if(ind >= pre.size() || pre[ind] <= minE || pre[ind] >= maxE) return;
        
        int curVal = pre[ind];
        // cunstruct left subtree
        if(curVal < root->val) {
            root->left = new TreeNode(curVal);
            ind++;
            buildBSTOPT(pre, root->left, minE, root->val);
        }
        
        if(ind >= pre.size() || pre[ind] <= minE || pre[ind] >= maxE) return;
        
        curVal = pre[ind];
        // cunstruct right subtree
        if(curVal > root->val) {
            root->right = new TreeNode(curVal);
            ind++;
            buildBSTOPT(pre, root->right, root->val, maxE);
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        /* insert in bst approach - O(n^2)
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < preorder.size(); ++i) {
            buildBST(root, preorder[i]);
        }
        return root;
        */        
        
        // optimises approach - O(N)
        TreeNode* root = new TreeNode(preorder[0]);
        buildBSTOPT(preorder, root);
        return root;
    }
};
