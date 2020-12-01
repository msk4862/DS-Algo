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
    int tilt = 0;
    
    int fsum(TreeNode* r) {
        if(!r) return 0;
        if(!r->left and !r->right) return r->val;
        
        int l=0,ri=0;
        
        l = fsum(r->left); 
        ri = fsum(r->right);
        
        tilt+=abs(l-ri);
        
        return l+ri+r->val;
        
    }
        
    int findTilt(TreeNode* root) {
        if(!root or (!root->left and !root->right)) return 0;
        fsum(root);
        
        return tilt;
    }
};




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
    // {tiltSum, nodeSum}
    vector<int> getSumTilt(TreeNode* r) {
        if(!r) return {0, 0};
        
        vector<int> left = getSumTilt(r->left);
        vector<int> right = getSumTilt(r->right);
        
        // finding tilt of cur node
        int curNodeTilt = abs(left[1]-right[1]);
        
        return {curNodeTilt + left[0] + right[0], left[1]+right[1]+r->val};
    }
    
    int findTilt(TreeNode* root) {
        return getSumTilt(root)[0];   
    }
};
