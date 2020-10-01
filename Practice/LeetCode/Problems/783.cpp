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

    vector<int> res;
public:
    void inorder(TreeNode* r) {
        if(!r) return;
        inorder(r->left);
        res.push_back(r->val);
        inorder(r->right);

    }
    
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int dif=INT_MAX;
        for(int i = 0; i < res.size()-1; ++i) dif=min(dif, abs(res[i]-res[i+1]));   
        return dif;
        
    }
};