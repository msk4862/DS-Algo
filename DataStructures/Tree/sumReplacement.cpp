int sum(TreeNode* root) {
	if(!root->left && !root->right) return root->val;
	
	int leftSubtreeSum =  sum(root->left);
	int rightSubtreeSum =  sum(root->right);
	
	int curRoot = root->val;
	root->val = leftSubtreeSum + rightSubtreeSum;
	
	return root->val + curValue;
	
}

void sumReplacement(TreeNode* root) {
	if(!root) return;
	sum(root);
}

int main() {
	buildtree();
}
