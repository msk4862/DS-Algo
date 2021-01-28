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
class BSTIterator {
public:
    stack<TreeNode*> num;
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    // O(h) but O(n) in worst case (if tree is skewed)
    void pushAllLeft(TreeNode* root) {
        if(!root) return;
        while(root) {
            num.push(root);
            root = root->left;
        }
    }
    
    /* next function can be called n times at most, and the number of right nodes in pushAllLeft(cur->right) 
    function is maximal n in a tree which has n nodes, so the amortized time complexity is O(1).
    */
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = num.top();
        num.pop();
        
        // storing left of all right subtree
        pushAllLeft(cur->right);
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !num.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
