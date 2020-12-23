#include<bits/stdc++.h>
using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr) {
			val = v;
			left = l;
			right = r;
		}
};

TreeNode* buildTree() {
	int cur;
	cout<<"Enter Node value (-1 for null)";
	cin>>cur;
	
	if(cur == -1) return nullptr;
	TreeNode* root = new TreeNode(cur);
	
	// build left subtree
	root->left = buildTree();
	
	// build right subtree
	root->right = buildTree();
	return root;
}

void print(TreeNode* root) {
	if(!root) return;
	
	cout<<root->val<<endl;
	print(root->left);
	print(root->right);
}

int main() {
	TreeNode* root = buildTree();
	print(root);
}
