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
    // height, isBalanced
    pair<int, bool> isBalancedHelper(TreeNode* root) {
        if(!root) return {0, true};
        
        // post order traversal
        auto left = isBalancedHelper(root->left);
        auto right = isBalancedHelper(root->right);
        
        int curHeight = max(left.first, right.first) +1;
        bool isBalance = left.second && right.second && abs(left.first - right.first) <= 1;
        
        return { curHeight, isBalance };
    }
    
    int isBalancedHelper1(TreeNode* root) {
        if(!root) return 0;
        
        // post order traversal
        int leftH = isBalancedHelper1(root->left);
        int rightH = isBalancedHelper1(root->right);
        
        // not balanced
        if(leftH == -1 || rightH == -1 || abs(leftH-rightH) > 1) return -1;
        
        // cur height
        return max(leftH, rightH)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        // return isBalancedHelper(root).second;
        return isBalancedHelper1(root) != -1;
    
    }
};
