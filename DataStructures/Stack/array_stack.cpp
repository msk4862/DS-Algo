#include<iostream>

using namespace std;

class ArrayStack {
    private:
        int size;
        int top;
        int* Stack;

    public:
        ArrayStack(int size) {
            top = -1;
            this->size = size;
            Stack = new int[size];
        }

        void push(int e);
        int pop();
        bool isEmpty();
        void print();
};

void ArrayStack::push(int e) {
    if (top >= size-1) {
        cout<<"\nOVERFLOW!";
        return;
    }  

    Stack[++top] = e;
}


int ArrayStack::pop() {
    if (!isEmpty()) {
        int e = Stack[top];
        --top;
        return e;
    } 
    cout<<"\nUNDERFLOW!";
}


bool ArrayStack::isEmpty() {
    return top==-1;    
}

void ArrayStack::print() {
    if(!isEmpty()) {
        for(int i = 0; i <= top; ++i) {
            cout<<Stack[i]<<" ";
        }
        cout<<endl;
    } else {
        cout<<"\nStack is Empty!";
    }
}

int main() {
    ArrayStack stack(5);
    cout<<stack.isEmpty()<<endl;
    stack.push(2);
    stack.push(3);
    stack.push(24);
    stack.push(6);
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.pop();

    stack.print();
}