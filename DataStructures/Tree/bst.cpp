#include<iostream>
#include<cstdlib>

using namespace std;

//Tree node
template <typename T>
class node  {

    public:
        T data; 
        node<T> *parent; 
        node<T> *left; 
        node<T> *right; 

        node(T data, node<T>* parent = NULL, node<T>* left = NULL, node<T>* right = NULL) {
            this->data = data;
            this->parent = parent;
            this->left = left;
            this->right = right;
        }
};

template <typename T>
class bst {
    private:
        node<T> *root;
    public:
        bst(node<T>* root = NULL) {
            this->root = root;
        }

        void insert_node(node<T>* newNode);
        void delete_node(node<T>* Node);
        void inOrder(node<T>* Node);

        void transplant(node<T>* u, node<T>* v);
        node<T>* successor(node<T>* Node);
        node<T>* getRoot();

};

template <typename T>
void bst<T>::insert_node(node<T>* newNode) {
    node<T>* parent = NULL;
    node<T>* temp = root;

    while(temp != NULL) {
        parent = temp;
        if(temp->data > newNode->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    newNode->parent = parent;
    if(newNode->parent == NULL) {
        // tree is empty
        root = newNode;
    }
    else if (newNode->data < parent->data) {
        parent->left = newNode;

    } else {
        parent->right = newNode;

    }


}

template <typename T>
void bst<T>::transplant(node<T>* u, node<T>* v) {
    if(u->parent == NULL) {
        root = v;
    }
    else if(u == u->parent->left) {
        // u is left child
        u->parent->left = v;
    }
    else {
        // u is right child
        u->parent->right = v;
    }

    if(v != NULL) {
        v->parent = u->parent;
    }
}

template <typename T>
node<T>* bst<T>::successor(node<T>* Node) {

    while (Node->left != NULL) {
        Node = Node->left;
    }

    return Node;
}



template <typename T>
void bst<T>::delete_node(node<T>* Node) {

    if(Node->left ==  NULL) {
        // has only right child or no child
        transplant(Node, Node->right);
    } 

    else if(Node->right ==  NULL) {
        // has only left child
        transplant(Node, Node->left);
    } 

    else {
        // has both child
        node<T>* succ = successor(Node->right);
        if (succ->parent == Node) {
            // succ right may not is not null
            // making it with its right child
            transplant(succ, succ->right);
            succ->right = Node->right;
            succ->right->parent = succ;
        }

        //replace node with successor
        transplant(Node, succ);
        succ->left = Node->left;
        succ->left->parent = succ;

    }

    delete Node;
    
}

template <typename T>
void bst<T>::inOrder(node<T>* Node) {
    if(Node == NULL) {
        return;
    } 
    inOrder(Node->left);
    cout<<Node->data<<", ";
    inOrder(Node->right);
}


template <typename T>
node<T>* bst<T>::getRoot() {
    return root;
}


int main() {

    bst<int> bin_search;

    node<int>* a = new node<int>(10);
    bin_search.insert_node(a);

    node<int>* b = new node<int>(17);
    bin_search.insert_node(b);

    
    node<int>* c = new node<int>(5);
    bin_search.insert_node(c);

    
    node<int>* d = new node<int>(29);
    bin_search.insert_node(d);

    
    node<int>* e = new node<int>(1);
    bin_search.insert_node(e);


    bin_search.inOrder(bin_search.getRoot());
    cout<<"\n";

    bin_search.delete_node(a);

    bin_search.inOrder(bin_search.getRoot());

}