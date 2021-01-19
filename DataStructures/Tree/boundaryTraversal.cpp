#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int _val, TreeNode* _left = nullptr, TreeNode* _right = nullptr) {
		val = _val;
		left = _left;
		right = _right;
	}
};

void leftBoundary(TreeNode* root, vector<int> &res) {
	if(!root) return;
	// left most non-leaf nodes only

	if (root->left) {
		res.push_back(root->val);
		leftBoundary(root->left, res);
	}
	else if(root->right) {
		res.push_back(root->val);
		leftBoundary(root->right, res);
	}
}


void rightBoundary(TreeNode* root, vector<int> &res) {
	if(!root) return;
	// right most non-leaf nodes only

	if (root->right) {
		res.push_back(root->val);
		leftBoundary(root->right, res);
	}
	else if(root->left) {
		res.push_back(root->val);
		rightBoundary(root->left, res);
	}
}

// dfs
void leafNodes(TreeNode* root, vector<int> &res) {
	if(!root) return;


	leafNodes(root->left, res);
	leafNodes(root->right, res);

	if(!root->left && !root->right) res.push_back(root->val);
} 

void boundaryTraversal(TreeNode* root) {
	if(!root) return {};

	vector<int> res;

	leftBoundary(root, res);
	leafNodes(root, res);
	rightBoundary(root->right, res);

	for (int i = 0; i < res.size(); ++i) {
		cout<<res[i]<<" ";
	}
}

int main() {
    
    struct TreeNode* root = new TreeNode(20); 
    root->left = new TreeNode(8); 
    root->left->left = new TreeNode(4); 
    root->left->right = new TreeNode(12); 
    root->left->right->left = new TreeNode(10); 
    root->left->right->right = new TreeNode(14); 
    root->right = new TreeNode(22); 
    root->right->right = new TreeNode(25); 
  
    boundaryTraversal(root); 

    return 0;
}