// https://www.geeksforgeeks.org/find-the-largest-subtree-in-a-tree-that-is-also-a-bst/
#include <bits/stdc++.h>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
struct Status {
    int maxVal;
    int minVal;
    bool isBST;
    int largestBSTSize;

    Status(int _maxVal, int _minVal, bool _isBST, int _largestBSTSize) {
        maxVal = _maxVal;
        minVal = _minVal;
        isBST = _isBST;
        largestBSTSize = _largestBSTSize;
    }

};

class Solution {
public:


    // using simple diamter problem template 
    Status* largestBSTHelper(TreeNode* root) {
        if(!root) return new Status(INT_MIN, INT_MAX, true, 0);

        Status* leftStatus = largestBSTHelper(root->left);
        Status* rightStatus = largestBSTHelper(root->right);
        
        int maxVal = max(rightStatus->maxVal, root->val);
        int minVal = max(leftStatus->minVal, root->val);

        int largestBSTSize = max(leftStatus->largestBSTSize, rightStatus->largestBSTSize);
        bool isBST = false;

        // chack if cur root can expand BST
        if(leftStatus->isBST && rightStatus->isBST && leftStatus->maxVal < root->val && root->val < rightStatus->minVal) {
            largestBSTSize = leftStatus->largestBSTSize + rightStatus->largestBSTSize + 1;
            isBST =true;
        }
        return new Status(maxVal, minVal, isBST, largestBSTSize);
    }

    int largestBST(TreeNode* root) {
        return largestBSTHelper(root)->largestBSTSize;
    }
};

int main(int argc, char const *argv[])
{
    
    TreeNode *root = new TreeNode(50);  
    root->left = new TreeNode(90);  
    root->right = new TreeNode(60);  
    root->left->left = new TreeNode(5);  
    root->left->right = new TreeNode(20);  
    root->right->left = new TreeNode(55);  
    root->right->left->left = new TreeNode(45);  
    root->right->right = new TreeNode(70);  
    root->right->right->left = new TreeNode(65);  
    root->right->right->right = new TreeNode(80);  

    Solution s;
    cout<<s.largestBST(root)<<" ";

    return 0;
}