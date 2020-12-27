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
    
    TreeNode*  flattenH(TreeNode* root) {
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
    
    // head, tail
    pair<TreeNode*,TreeNode*>  flattenH1(TreeNode* root) {
        if(!root) return { nullptr, nullptr};
        
        // single node
        if(!root->left && !root->right) return {root, root};

        // if left is null and right is not null
        if(!root->left && root->right) {
            auto right = flattenH1(root->right);
            
            root->right = right.first;
            return {root, right.second};
        }

        // if left is not null and right is null
        if(root->left && !root->right) {
            auto left = flattenH1(root->left);
            
            root->right = left.first;
            root->left = nullptr;
            return {root, left.second};
        }
                
        
        // if both left and right subtree exist
        auto left = flattenH1(root->left);
        auto right = flattenH1(root->right);
        
        cout<<left.first->val<<" ";
        
        root->right = left.first;
        left.second->right = right.first;
        
        root->left = nullptr;
        return { root, right.second};
    }
    
        
    void flatten(TreeNode* root) {
        flattenH1(root);
    }
};
