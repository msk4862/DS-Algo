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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> t;
            long int sum = 0, count=0;
            
            while(!q.empty()) {
                TreeNode* n = q.front();
                
                sum+=n->val;
                count++;
                            
                if(n->left)
                    t.push(n->left);

                if(n->right)
                    t.push(n->right);
                q.pop();
            }
            
            res.push_back((double)sum/count);
            
            q = t;
        }
                
        return res;
    }
};
