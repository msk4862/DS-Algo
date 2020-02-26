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
        node<T> *cursor;
    
    public:
        clist() {
            cursor = NULL;
        }

    void add(T data);
    void remove();
    T front();
    T back();
    void advance();

    void print();

};

template <typename T>
T clist<T>::front() {

    if(cursor == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return -1;
    } 

    return cursor->next->data;
}

template <typename T>
T clist<T>::back() {

    if(cursor == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return -1;
    } 

    return cursor->data;
}

template <typename T>
void clist<T>::add(T data) {
    node<T> *ptr = new node<T>(data);

    if(cursor == NULL) {
        cursor = ptr;
        ptr->next = cursor;
        return;
    } 

    ptr->next = cursor->next;
    cursor->next = ptr;

}

template <typename T>
void clist<T>::remove() {

    if(cursor == NULL) {
        cout<<"\nUNDERFLOW!!!";
        return;

    } 

    //single element list
    else if(cursor->next = cursor) {
        cursor = NULL;
        return;
    }

    node<T> *ptr = cursor->next;

    cursor->next = ptr->next;

    delete ptr;
    return;
}

template <typename T>
void clist<T>::advance() {

    if(cursor == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return;
    } 

    cursor = cursor->next;
}

template <typename T>
void clist<T>::print() {
    if(cursor == NULL) {
        cout<<"\nLIST IS EMPTY!!!";
        return;
    }
    node<T> *ptr = cursor->next;

    cout<<"Your list: ";
    while (ptr != cursor)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next; 
    }
    cout<<ptr->data<<endl;
    
}


int main() {
    clist<char> li;

    int ch;

    do {
        cout<<"\n1. Get front\n";
        cout<<"\n2. Get back\n";
        cout<<"\n3. Add an element\n";
        cout<<"\n4. Remove an element\n";
        cout<<"\n5. Advance the cursor\n";
        cout<<"\n6. Print the list\n";
        cout<<"\n\nEnter anything else to EXIT\n";
        cout<<"\nEnter your choice: \n";
        
        cin>>ch;

        switch (ch)
        {
            char e;
            int pos;
        case 1:
            e = li.front();
            if(e != -1) {
                cout<<"\nFRONT: "<<e<<endl;
            }
            break;
        
        case 2:
            e = li.back();
            if(e != -1) {
                cout<<"\nBACK: "<<e<<endl;
            }
            break;
        
        case 3:
            cout<<"\nEnter an element to be inserted: ";
            cin>>e;
            li.add(e);
            li.print();
            break;
        
        case 4:
            li.remove();
            li.print();
            break;

        case 5:
            li.advance();
            li.print();
            break;

        case 6:
            li.print();
            break;
        
        default:
            exit(0);
        }
        
    }while(true);
        
}

