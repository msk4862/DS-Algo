#include<iostream>
#include<cstdlib>

using namespace std;

//Tree node
template <typename T>
class node  {

    public:
        T data; 
        node<T> *par;
        node<T> *left; 
        node<T> *right; 

        node(T data, node<T>* par = NULL, node<T>* left = NULL, node<T>* right = NULL) {
            this->data = data;
            this->par = par;
            this->left = left;
            this->right = right;
        }
};

template <typename T>
class btree {
    private:
        node<T> *root;
        int size;
    public:
        btree(node<T>* root = NULL) {
            this->root = root;
            size = 0;
        }
        int getSize();
        bool isEmpty();
        void addRoot(T data);
        
        void expandExternal(node<T>* n, T left, T right); 
        node<T>* removeAboveExternal(node<T>* n);

        void preOrder(node<T>* root);
        void postOrder(node<T>* root);
        void inOrder(node<T>* root);

};

template <typename T>
int btree<T>::getSize() {
    return size;
}


template <typename T>
bool btree<T>::isEmpty() {
    return size==0;
}


template <typename T>
void btree<T>::addRoot(T data) {
    node<T>* n = new node<T>(data);
    root = n;
    size += 1;
}

template <typename T>
void btree<T>::expandExternal(node<T>* n, T left, T right) {
    if(n->left != NULL || n->right != NULL) {
        cout<<"\nERROR!!\nGiven node is an internal node!\n";
        return;
    }

    n->left = new node<T>(left, n);
    n->right = new node<T>(right, n);
    size +=2;
}

//remove node n and its parent
template <typename T>
node<T>* btree<T>::removeAboveExternal(node<T>* n) {
    if(n->left != NULL || n->right != NULL) {
        cout<<"\nERROR!!\nGiven node is an internal node!\n";
        return NULL;
    } else if(n == root) {
        cout<<"\nERROR!!\nGiven node is root!\n";
        return NULL;
    } 

    node<T>* parent = n->par;
    node<T>* sibling = parent->left == n ? parent->right: parent->left;

    // if given node parent is root
    if(parent == root) {
        root = sibling;
        root->par = NULL;
    } 
    else {
        node<T>* grand = parent->par;
        if(sibling == parent->left) {
            sibling->par = grand;
            grand->left = sibling;
        } else {
            sibling->par = grand;
            grand->right = sibling;
        }
    }
    delete parent;
    delete n;
    size -= 2;

    return sibling;
}

template <typename T>
void btree<T>::preOrder(node<T>* node) {
    if(node == NULL) {
        return;
    } 
    //traverse node
    cout<<node->data;
    cout<<preOrder(node->left);
    cout<<preOrder(node->right);
}

template <typename T>
void btree<T>::postOrder(node<T>* node) {
    if(node == NULL) {
        return;
    } 
    //traverse node
    cout<<node->data;
    cout<<preOrder(node->left);
    cout<<preOrder(node->right);
}

template <typename T>
void btree<T>::inOrder(node<T>* node) {
    if(node == NULL) {
        return;
    } 
    //traverse node
    cout<<node->data;
    cout<<preOrder(node->left);
    cout<<preOrder(node->right);
}

int main() {
    btree<int> t;
    cout<<t.isEmpty();
}