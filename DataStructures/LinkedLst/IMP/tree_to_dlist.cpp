#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* pre;
        Node* next;

        Node(int val) {
            pre = next = nullptr;
            this->val = val;
        }
};

class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value, Node* l=nullptr, Node* r = nullptr) {
            val = value;
            left = nullptr;
            right = nullptr;
        }

};

Node* connect(Node* h1, Node* h2) {

    // both null
    if(!h1 && !h2) return nullptr;

    // either is null
    if(!h1 || !h2) {
        if(h1) return h1;
        if(h2) return h2;
    } 
    // both are not null

    Node* tail2 = h2->pre;

    // mid connection
    h1->pre->next = h2;
    h2->pre = h1->pre;

    // tail connection
    h1->pre = tail2;
    tail2->next = h1;

    return h1;
}


Node* convert(TreeNode* root) {
    if(!root) return nullptr;

    Node* leftHead = convert(root->left);
    Node* rightHead = convert(root->right);

    Node* n = new Node(root->val);
    n->pre =n;
    n->next = n;

    return connect(connect(leftHead, n), rightHead);
}

int main() {
    TreeNode *root = new TreeNode(10); 
    root->left = new TreeNode(12); 
    root->right = new TreeNode(15); 
    root->left->left = new TreeNode(25); 
    root->left->right = new TreeNode(30); 
    root->right->left = new TreeNode(36); 

    Node* head = convert(root);

    cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do
    { 
        cout << itr->val <<" "; 
        itr = itr->next; 
    } while (head!=itr); 
    cout << "\n"; 

    return 0;
}