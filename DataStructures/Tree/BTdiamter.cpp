#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


class TreeNode {

    public:
        
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            this->val = val;
            left=NULL;
            right = NULL;
        }
};

int diameter = 0;

int height(TreeNode* root) {
    if(!root) return 0;

    int l, r;
    l = height(root->left);
    r = height(root->right);

    // update diameter
    diameter = max(diameter, l+r+1);

    return max(l, r)+1;
}


int main() { 
    TreeNode* root = new TreeNode(5);

    TreeNode* n1 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n1 = new TreeNode(4);

    return 0;
}