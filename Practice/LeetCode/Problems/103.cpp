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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int alt=1;
                
        while(!q.empty()) {
            queue<TreeNode*> level;
            vector<int> l;
            
            while(!q.empty()) {    
                TreeNode* cur = q.front();
                
                if(alt==1)
                    l.push_back(cur->val);
                else
                    l.insert(l.begin(), cur->val);
                
                if(cur->left)
                    level.push(cur->left);
                if(cur->right)
                    level.push(cur->right);
                q.pop();
            }
            q = level;
            res.push_back(l);
            alt*=-1;

        }
        
        return res;
    }
};
