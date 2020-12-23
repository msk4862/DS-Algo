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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> res;
        stack<TreeNode*> st;
        
        do {
            // left subtree
            while(root) {
                st.push(root);
                cout<<root->val<<" ";

                root = root->left;
            }
            
            // root
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);
            
            // right subtree
            if(cur->right) {
                root = cur->right;
            }
        }while(!st.empty() || root);
    
        return res;
    }
};
