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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector<int> post;
        stack<TreeNode*> st;
        
        do {
            
            while(root) {
                
                if(root->right) st.push(root->right);                
                st.push(root);
                
                root = root->left;
            }
            
            TreeNode* cur = st.top();
            st.pop();
            
            // to verify if its right subtree has not been traversed yet
            if(cur->right && !st.empty() && st.top() == cur->right) {
                //remove cur's right child
                st.pop();
                // that will be traversed after right subtree has been travrsed
                st.push(cur);
                
                root = cur->right;
            }
            else {
                post.push_back(cur->val);
            }
        }while(!st.empty());
        
        return post;
    }
};
