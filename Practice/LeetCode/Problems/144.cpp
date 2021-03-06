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
    vector<int> res;
    void pre(TreeNode* r) {
        if(!r) return;
        res.push_back(r->val);
        pre(r->left);
        pre(r->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return res;
    }
};

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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> res;
        stack<TreeNode*> st;
        
        do {
            while(root) {
                // root
                res.push_back(root->val);
                
                // left subtree
                st.push(root);
                
                root = root->left;
            }
            
            TreeNode* cur = st.top();
            st.pop();
            
            // right subtree
            if(cur->right) {
                root = cur->right;
            }
        }while(!st.empty() || root);
            
        return res;
    }
};
