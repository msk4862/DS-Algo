#include <iostream> 
using namespace std; 

// To find x in arr[] of size n 
int find(int arr[], int key, int n) 
{ 
	for (int i = 0; i < n; i++) 
		if (arr[i] == key) 
			return i; 
	return -1; 
} 

void getPostorder(int in[], int pre[], int n) 
{ 

	int root = find(in, pre[0], n); 

    // if left subtree is not null
	if (root != 0) 
		getPostorder(in, pre + 1, root); 


    // if right subtree is not null	
    if (root != n - 1) 
		getPostorder(in + root + 1, pre + root + 1, n - root - 1); 

	cout << pre[0] << " "; 
} 

int main() 
{ 
    int n;
    cout<<"Enter number of nodes present: ";
    cin>>n;

    int inorder[n], preorder[n];

	cout<<"\nInput inorder traversal: ";
	for(int i=0;i<n;i++) {
		cin>>inorder[i];
	}

	cout<<"\nInput preorder traversal: ";
	for(int i=0;i<n;i++) {
		cin>>preorder[i];
	}

	cout << "Postorder traversal " << endl; 
	getPostorder(inorder, preorder, n); 
	return 0; 
} 
