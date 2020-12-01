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

vector<TreeNode*> splitBST(TreeNode* root, int V) {
	TreeNode* cur = root;
	TreeNode* par = nullptr;

	while(cur && cur->val > V ) {
		par = cur;
		cur = cur->left;
	}
	
	TreeNode* large = cur;
	TreeNode* largeP = nullptr;
	
	while(large && large->val <= V) {
		largeP = large;
		large = large->right;
	}
	
	
    if(cur == root) {
		root = large;
    }

	// set larger subtree of small subtree
	if(par) {
		par->left = large;
	}
	
	// set large subtree parent's null 
	if(largeP) largeP->right = nullptr;


	return vector<TreeNode*> {cur, root};
}

void in(TreeNode* r) {
    if(!r) return;
    in(r->left);
    cout<<r->val<<" ";
    in(r->right);
}

int main() {
	TreeNode* root = new TreeNode(4);
	
	root->left = new TreeNode(2);;
	root->right = new TreeNode(6);;

	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);

	vector<TreeNode*> r = splitBST(root, 4);
// 	cout<<r[0]->val<<" "<<r[1]->val;
    
    in(r[0]);
    cout<<endl;
    in(r[1]);
}
