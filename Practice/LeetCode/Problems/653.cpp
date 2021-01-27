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
    
    bool findTargetHelper1(TreeNode* root, int  k, unordered_map<int, bool> &mp) {
        if(!root) return false;
        
        if(mp[k-root->val]) return true;
        
        mp[root->val] = true;
        return findTargetHelper1(root->left, k, mp) || findTargetHelper1(root->right, k, mp);
    }
    
    bool findTarget(TreeNode* root, int k) {
        // 1st approach
        // O(n), O(n)
        unordered_map<int, bool> mp;
        return findTargetHelper1(root, k, mp); 
        
        // 2nd approach
        // do inorder traversal and store result in array
        // now problem is reduced to finding two sum in sorted array 
        // O(n), O(n)
    }
};
