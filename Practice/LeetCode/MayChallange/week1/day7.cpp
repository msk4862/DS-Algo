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
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            bool exist_x= 0;
            bool exist_y= 0;

            for(int i = 0; i < size; ++i) {
                TreeNode* n = q.front();
                
                if(n->val == x) exist_x = 1;
                if(n->val == y) exist_y = 1;
                
                if(n->left && n->right) {
                    if(n->left->val == x and n->right->val == y) {
                        return 0;
                    }
                    else if(n->left->val == y and n->right->val == x) {
                        return 0;
                    }
                }
                q.pop();
                
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
                
            }
            
            if(exist_x || exist_y)
                if(exist_x && exist_y) return 1;
                else return 0;
        }
        
        return 0;
    }
};