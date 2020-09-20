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
    void leaf(TreeNode* r, vector<int>& res) {
        if(!r) return;
        if( !r->left && !r->right) {
            res.push_back(r->val);
            return;
        }
        
        if(r->left) leaf(r->left, res);
        if(r->right) leaf(r->right, res);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        leaf(root1, l1);
        leaf(root2, l2);
        
        if(l1.size() != l2.size()) return false;
        
        for(int i = 0; i < l1.size(); ++i) {
            if(l1[i] != l2[i]) return false;
        }
        
        
        for(auto e:l2)cout<<e<<" ";
        
        return true;
        
    }
};
