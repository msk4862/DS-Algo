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
    TreeNode* buildBST(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        
        int mid = (end -start)/2 + start;

        TreeNode* root = new TreeNode(nums[mid]);
        // build left subtree
        root->left = buildBST(nums, start, mid-1);
        // build right subtree
        root->right = buildBST(nums, mid+1, end);
        
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
};
