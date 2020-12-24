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
    bool calcSum(TreeNode* root, int sum, int curSum = 0) {
        if(!root) return false;
        
        if(!root->left && !root->right) {
            if(curSum + root->val == sum) {
                return true;
            }
            
            return false;
        }
        
        curSum += root->val;
        return calcSum(root->left, sum, curSum) || calcSum(root->right, sum, curSum);
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return calcSum(root, sum);
    }
};
