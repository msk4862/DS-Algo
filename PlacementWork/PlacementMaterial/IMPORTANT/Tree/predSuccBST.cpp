// https://www.geeksforgeeks.org/inorder-predecessor-successor-given-key-bst/
// https://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

void printPreSuccHelper(TreeNode root, int key, int &pred, int &succ) {
	if(!root) return;

	// found key in tree
	if(root->val == key) {
		// largest in left subtree
		pred = root->left;

		while(pred && pred->right) {
			pred = pred->right;
		}

		// smallest in right subtree
		succ = root->right;

		while(succ && succ->left) {
			succ = succ->left;
		}

		return;	
	}

	else if(root->val < key) {
		// possible predecessor
		pred = root->val;
		printPreSuccHelper(root->right, key, pred, succ);
	}
	else {
		// possible successor
		succ = root->val;
		printPreSuccHelper(root->left, key, pred, succ);
	}
}

void printPreSucc(TreeNode* root, int key) {
	int pred, succ;

	printPreSuccHelper(root, key, pred, succ);
}