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


void getVerticalOrder(TreeNode* root, int hd, map<int, vector<int>> &hd_map) {
    if(root == NULL) return;

    hd_map[hd].push_back(root->val);

    getVerticalOrder(root->left, hd-1, hd_map);
    getVerticalOrder(root->right, hd+1, hd_map);
}


void VerticalOrder(TreeNode* root) {

    map<int, vector<int>> hd_map;

    getVerticalOrder(root, 0, hd_map);

    for(auto line: hd_map) {
        cout<<line.first<<": ";
        for(auto e: line.second)
            cout<<e<<" ";
        cout<<endl;
    }

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