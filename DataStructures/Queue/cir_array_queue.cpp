#include<iostream>

using namespace std;

class ArrayQueue {
    //circular array implementation
    private:
        int front;
        int end;
        int size;
        int* Queue;

    public:
        ArrayQueue(int size) {
            front = -1;
            end = -1;
            Queue = new int[size];
        }

        void enqueue(int e);
        int dequeue();
        bool isEmpty();
        void print();
};

void ArrayQueue::enqueue(int e) {
    if (front == 0 && end == size-1) {
        cout<<"\nOVERFLOW!";
        return;
    } else if(front ==-1 && front==end+1) {
        cout<<"\nOVERFLOW!";
        return;
    } 
    
    if(end == -1) {
        front = 0;
    }
    end = (end+1)%size;
    Queue[end] = e;

}


int ArrayQueue::dequeue() {
    if (!isEmpty()) {

        int e = Queue[front];
        if(front == end) {
            //single element
            front=end=-1;
        } else {
            front = (front+1)%size;
        }

        return e;
    } 
    cout<<"\nUNDERFLOW!";
}


bool ArrayQueue::isEmpty() {
    if (front==-1 || front == end)
        return true;
    else 
        return false;
}

void ArrayQueue::print() {
    if(!isEmpty()) {
        if (front<=end) {
            for(int i = front; i <= end; ++i) {
                cout<<Queue[i]<<" ";
            }
        } else {
            for(int i = front; i < size; ++i) {
                cout<<Queue[i]<<" ";
            }
            for(int i = 0; i <= end; ++i) {
                cout<<Queue[i]<<" ";
            }
        }
        cout<<endl;
    } else {
        cout<<"\nQueue is Empty!";
    }
}

int main() {
    ArrayQueue queue(5);
    cout<<queue.isEmpty()<<endl;

    queue.enqueue(2);
    queue.enqueue(5);
    queue.enqueue(9);
    queue.enqueue(12);
    queue.enqueue(17);

    queue.print();
    
    queue.dequeue();
    queue.print();
    
        queue.enqueue(8);
    queue.print();
}