/*
      Construct Binary Search Tree from Preorder Traversal

*/



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
#define ll long long int

class Solution {
public:
    TreeNode* findPos(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->left == nullptr and root->right==nullptr)
            return root;
        
        if((root->val) <= key) {
            TreeNode* n = findPos(root->right, key);  
            
            // leaf node
            if(n == nullptr) return root;
            return n;
        }
        else {
            TreeNode* n = findPos(root->left, key);   
            
            // leaf node
            if(n == nullptr) return root;
            return n;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root= new TreeNode(preorder[0]);
        
        
        for(int i =1; i<preorder.size(); ++i) {
            int key = preorder[i];
            
            // get leaf node
            TreeNode* p = findPos(root, key);
            
            TreeNode* n= new TreeNode(key);      
            if(key < (p->val)) p->left = n;
            else p->right = n;
        }
        
        return root;
    }
};