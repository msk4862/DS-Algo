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
    // max Path sum 
    int maxPathSumHelper(TreeNode* root, int &maxOverall) {
        if(!root) return 0;
        
        int leftMaxSum = maxPathSumHelper(root->left, maxOverall);
        int rightMaxSum = maxPathSumHelper(root->right, maxOverall);
        
        // if cur node is included in path
        int includedInPath = max(max(leftMaxSum, rightMaxSum) + root->val, root->val);
        // if cur node is root of the max path
        int rootInPath = leftMaxSum + rightMaxSum + root->val;
        
        // maintain overall max
        maxOverall = max(maxOverall, max(rootInPath, includedInPath));
    
        // return for case if node is included in max path
        // then only you can add up more nodes in path
        return includedInPath;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxOverall = INT_MIN;
        maxPathSumHelper(root, maxOverall);
        
        return maxOverall;
    }
};
