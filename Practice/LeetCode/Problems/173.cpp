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
    
    /** @return the next smallest number */
    int next() {
        TreeNode* t = num.top();
        num.pop();
        // storing left of all right subtree
        pushAllLeft(t->right);
        return t->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !num.empty();
    }
    
    void pushAllLeft(TreeNode* root) {
        if(!root) return;
        num.push(root);
        pushAllLeft(root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */