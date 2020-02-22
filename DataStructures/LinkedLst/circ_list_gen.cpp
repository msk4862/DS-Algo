#include<iostream>
#include<cstdlib>

using namespace std;

template <typename T>
class node {
    public:
        T data;
        node<T>* next;

    node(T data, node<T>* next = NULL) {
        this->data = data;
        this->next = next;
    }

};

template <typename T>
class clist{
    private:
        node<T> *tail;
    
    public:
        clist() {
            tail = NULL;
        }

    void insert_first(T data);
    void insert_end(T data);
    // void insert_pos(T data, int pos);

    void delete_first();
    void delete_last();
    // T delete_pos(int pos);  

    void print();

};

template <typename T>
void clist<T>::insert_first(T data) {
    node<T> *ptr = new node<T>(data);
    if(tail == NULL) {

        tail = ptr;
        ptr->next = tail;

        return;

    } 

    ptr->next = tail->next;
    tail->next = ptr;

}

template <typename T>
void clist<T>::insert_end(T data) {
    node<T> *ptr = new node<T>(data);

    if(tail == NULL) {
        tail = ptr;
        ptr->next = tail;

        return;

    } 

    ptr->next = tail->next;
    tail->next = ptr;
    tail = ptr;

}

template <typename T>
void clist<T>::delete_first() {

    if(tail == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return;
    } 

    node<T> *ptr = tail->next;
    tail->next = ptr->next;
    
    delete ptr;
}

template <typename T>
void clist<T>::delete_last() {

    if(tail == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return;
    } 

    node<T> *ptr = tail;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    
    node<T> *temp = tail;
    ptr->next = tail->next;
    tail = ptr;

    delete temp;
}


template <typename T>
void clist<T>::print() {
    node<T> *ptr = tail->next;

    cout<<"Your list: ";
    while (ptr != tail)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }
    cout<<ptr->data<<endl;
    
}

int main() {
    clist<int> li;
    li.insert_first(1);
    li.print();
    
    li.insert_first(2);
    li.print();

    li.insert_first(3);
    li.print();
    
    li.insert_end(8);
    li.print();
    
    
    li.insert_end(5);
    li.print();
    
    li.delete_first();
    li.print();
    
    li.delete_last();
    li.print();
}

