https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/


#include<iostream>

using namespace std;

class ArrayStack {
    private:
        int size;
        int top;
        int* Stack;
        int min;

    public:
        ArrayStack(int size) {
            top = -1;
            this->size = size;
            Stack = new int[size];
            min = INT_MAX;
        }

        void push(int e);
        int pop();
        bool isEmpty();
        int getMin();
        void print();
};

void ArrayStack::push(int e) {
    if (top >= size-1) {
        cout<<"\nOVERFLOW!";
        return;
    }  

    if(size == 1) {
        min =e;
        Stack[++top] = e;
    }
    // new min (we store value less than original value)
    else if(min > e) {
        Stack[++top] = 2*e - min;
    }
    else {
        Stack[++top] = e;
    }
}


int ArrayStack::pop() {
    if (isEmpty())     cout<<"\nUNDERFLOW!";
    
    int e = Stack[top];
    // min element is 
    if(e < min) {
        min = 2*min - e;
    }

    --top;
    return e;

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

int ArrayStack::getMin() {

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