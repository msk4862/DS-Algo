#include<iostream>
using namespace std;


// NODE
class node
{
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this-> next = (node *) NULL;
        cout<<"Node of value "<<data<<" Created"<<endl;

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
    void delete_node(int pos);
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

void List::delete_node(int pos) {
    node *prev = (node *)NULL;
    node *cur = head;

    if (pos < 1) {
        cout<<"Invalid Position!"<<endl;
        return;
    }



    while(--pos) {
        prev = cur;
        cur = cur->next;

        if (cur == NULL) {
            cout<<"Invalid Position!"<<endl;
            return;
        }
    }

    if(cur == head) {
        // List has single element
        if (head == rear) {
            delete cur;
            head = rear = (node *) NULL;
        }
        else {
            head = head->next;
            delete cur;
        }     
    }

    else if(cur == rear) {
        rear = prev;
        delete cur;
    }
    
    else {
        prev->next = cur->next;
        delete cur;
    }

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

    list.delete_node(1);
    // list.delete_node(8);

    list.print();

}