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
    unordered_map<int, vector<TreeNode*>> dp;
    
    public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        
        // not possible
        if(N <= 0 || N%2 == 0) return res;        
        
        if(N == 1) {
            TreeNode* root = new TreeNode(0);
            res.push_back(root);
            return res;
        }
        
        // cout<<dp[N].size();
        if(dp[N].size() > 0) return dp[N];
        
        for(int i = 1; i < N; i+=2) {
            // N = i(left) + 1(root) + (N-i-1)right
            vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(N-i-1);
            
            // make all possible pairs
            for(TreeNode* leftTree: leftSubtrees) {
                for(TreeNode* rightTree: rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftTree;
                    root->right = rightTree;            
                    res.push_back(root);
                }
            }
            
        }
        
        return dp[N] = res;
    }
};
