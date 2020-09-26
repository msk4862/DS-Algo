// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void tra(TreeNode* r, int& sum, TreeNode* p=nullptr) {
//         if(!r->left && !r->right && r == p->left) 
//             sum+=r->val;
        
//         if(r->left) tra(r->left, sum, r);
//         if(r->right) tra(r->right, sum, r);
        
//     }
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(!root) return 0;
        
//         int sum = 0;
//         tra(root, sum, root);
//         return sum;
//     }
// };
