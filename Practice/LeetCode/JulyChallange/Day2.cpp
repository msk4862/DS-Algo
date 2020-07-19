//   Binary Tree Level Order Traversal II

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         node, level
        vector<vector<int>> tra;
        
        if(!root) return tra;

        queue<pair<TreeNode*, int>> nodes;
        nodes.push(make_pair(root, 1));
        
        int curlevel = 1;
        vector<int> level_n;
        
        while(!nodes.empty()) {
            TreeNode* cur = nodes.front().first;
            int level = nodes.front().second;
            
            if(curlevel == level) {
                cout<<cur->val<<" "<<level<<endl;
                level_n.push_back(cur->val);
            } else {
                tra.insert(tra.begin(), level_n);
                level_n.clear();
                
                cout<<cur->val<<" "<<level<<endl;

                level_n.push_back(cur->val);
                curlevel = level;
            }
            
            
            cout<<cur->val<<" "<<level<<endl;
            // tra.
            if(cur->left)
            nodes.push(make_pair(cur->left, level+1));
            if(cur->right)
            nodes.push(make_pair(cur->right, level+1));
            nodes.pop();
        }
        
        // last level
        tra.insert(tra.begin(), level_n);

        
        return tra;
    }
};