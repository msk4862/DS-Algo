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
    // O(n^2) solution
    /*
    int height(TreeNode* r) {
        if(!r) return 0;
        
        return max(height(r->left), height(r->right)) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        // if diameter passes through root  
        int d1 = leftH + rightH;
        
        // if diameter  lies in left subtree
        int d2 = diameterOfBinaryTree(root->left);
        // if diameter lies in right subtree
        int d3 = diameterOfBinaryTree(root->left);
        
        return max(d1, max(d2, d3));
    }*/
    
    // height, diameter
    pair<int, int> diameter(TreeNode* root) {
        if(!root) return {0, 0};
        
        
        // post order traversal
        auto left = diameter(root->left);
        auto right = diameter(root->right);
        
        // all 3 possibilities of diamter 
        int curDiamter = max(left.first + right.first, max(left.second, right.second));
        int curHeight = max(left.first, right.first) + 1;
        return {curHeight, curDiamter};
    }
    
    // optimized approach - O(n)
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        auto res = diameter(root);
        
        return res.second;
    }
};
