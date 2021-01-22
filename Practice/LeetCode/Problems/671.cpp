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
    // using dfs
    int minValue(TreeNode* root, int minVal) {
        if(!root) return -1;
        
        if(root->val != minVal) return root->val;
        
        int leftMin = minValue(root->left, minVal);
        int rightMin = minValue(root->right, minVal);
        
        if(leftMin == -1 && rightMin ==-1) return -1;
        if(leftMin == -1 || rightMin ==-1) return leftMin == -1 ? rightMin : leftMin;
        return min(leftMin, rightMin);
    }
    
    //using bfs 
    // we need to find min value of the entire current level, level by level
    // if that min val is not equal to root then just return it
    
        // root val will be minimum
        // so we have find minimum value other than root val
    int findSecondMinimumValue(TreeNode* root) {
        
        return minValue(root, root->val);
        
    }
};
