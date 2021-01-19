
// do topview, side view , etc. questions using tree to 2-d place coordinate system mapping
// with root as (0,0), down the tree: +y, left the root: -x, right the tree: +x 


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


// using BFS to mantain vertcal order 
void verticalTraversalBFS(TreeNode* root, map<int, vector<int>> &h_dist) {
    // node, horizontal distance
    queue<pair<TreeNode*, int>> cur_level;
    cur_level.push({root, 0});
    
    while(!cur_level.empty()) {
        
        auto cur = cur_level.front();
        cur_level.pop();

        int hd = cur.second;
        TreeNode* curNode = cur.first;

        h_dist[hd].push_back(curNode->val);   

        if(curNode->left) {
            cur_level.push({curNode->left, hd-1});
        }
        if(curNode->right) {
            cur_level.push({curNode->right, hd+1});
        }
        
    }
}



void VerticalOrder(TreeNode* root) {

    map<int, vector<int>> hd_map;

    // getVerticalOrder(root, 0, hd_map);
	verticalTraversalBFS(root, hd_map);
    
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