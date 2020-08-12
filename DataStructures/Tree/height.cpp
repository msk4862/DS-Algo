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

unordered_map<int, int> height;

int nodeHeight(TreeNode* root) {
    if(root)
    if(root==NULL or (root->left and root->right)) {
        
        return 0;
    }
    int h = max(nodeHeight(root->left), nodeHeight(root->right))+1;

    height[root->val] = h;

    return h;

}

int main() {
    TreeNode* root = new TreeNode(5);

    nodeHeight(root);
    return 0;
}