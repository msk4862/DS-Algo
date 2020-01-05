#include<iostream>
using namespace std;


// NODE
class node
{
public:
    int data;
    node *next;

    node(int data) {
        cout<<"Node Created"<<endl;
        this->data = data;
        this-> next = (node *) NULL;
    }
};


// LIST
class List {

private:
    node *head;
    node *rear;
public:
    List() {
        cout<<"Empty list created"<<endl;
        head = (node*) NULL;
        rear = (node*) NULL;
    }

    void insert_end(int data);
    void insert_front(int data);
    void print();
};

void List :: insert_front(int data) {
    node *n = new node(data);

    if(head == NULL) {
        head = rear= n;
        return;
    }

    n->next = head;
    head = n;
}

void List::insert_end(int data) {
    node *n = new node(data);

    if(head == NULL) {
        head = rear= n;
        return;
    }

    rear->next = n;
    rear = n;
}

void List:: print() {
    node *n = head;

    cout<<"Your List: ";
    while (n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }

    cout<<endl;
    
}


int main() {
    List list;
    list.print();
    list.insert_front(5);
    list.insert_front(3);

    list.insert_end(8);
    list.insert_end(4);

    list.print();

}