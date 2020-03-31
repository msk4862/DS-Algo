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


class Stack {

private:
    node *top;
public:
    Stack() {
        cout<<"Stack created"<<endl;
        top = NULL;
    }

    void push(int data);
    int pop();
    bool isEmpty();
    void print();
};

//insertion at front
void Stack::push(int data) {
    node *n = new node(data);

    if(isEmpty()) {
        top = n;
        return;
    }
    
    n->next = top;
    top = n;
}

//deletion from head
int Stack::pop() {
    
    if(isEmpty()) {
        cout<<"\nUnderflow!";
        return -1;
    }
    node* temp = top;
    top = top->next;
    int e = temp->data;
    delete temp;
    return e;
     
}

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack:: print() {
    node *n = top;

    cout<<"Your Stack (starting with top): ";
    while (n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }

    cout<<endl;   
}


int main() {

    Stack stack;
    
    stack.push(2);
    stack.push(5);
    stack.push(6);
    stack.print();
    stack.pop();
    stack.print();
}