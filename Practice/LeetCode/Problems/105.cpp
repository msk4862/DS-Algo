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
    // also can improve time complexity by caching inorder array
    // if no duplicates
    
    int findRoot(vector<int> inorder, int start, int end,  int val) {
        for(int i = start; i <= end; ++i) {
            if(inorder[i] == val) return i;
        }
        return -1;
    }
    
    int preInd = 0;
    
    TreeNode* buildTreeH(vector<int>& preorder, unordered_map<int, int> inorderMap, int start, int end){
        
        if(preInd >= preorder.size() || start > end) {
            preInd--;
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preInd]);
        // int curRootInd =  findRoot(inorder, start, end, root->val);
        int curRootInd = inorderMap[root->val];
        cout<<curRootInd;
        preInd++;
        root->left = buildTreeH(preorder, inorderMap, start, curRootInd-1);
        preInd++;
        root->right = buildTreeH(preorder, inorderMap, curRootInd+1, end);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        
        return buildTreeH(preorder, mp, 0, inorder.size()-1); 
    }
};
