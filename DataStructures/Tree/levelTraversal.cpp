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
    void level(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> t;

            
            while(!q.empty()) {
                TreeNode* n = q.front();
                 
                cout<<n->val<<" ";
                if(n->left)
                    t.push(n->left);

                if(n->right)
                    t.push(n->right);
                q.pop();
            }
            

            
            q = t;
        }
                
    }
};
