#include<iostream>
#include<cstdlib>

using namespace std;

template <typename T>
class node {
    public:
        T data;
        node<T>* next;
        node<T>* prev;

    node(T data, node<T> *prev = NULL, node<T>* next = NULL) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

};

template <typename T>
class dlist{
    private:
        node<T> *head;
        node<T> *tail;
    
    public:
        dlist() {
            head = NULL;
            tail = NULL;
        }

    void insert_first(T data);
    void insert_end(T data);
    void insert_pos(T data, int pos);

    T delete_first();
    T delete_last();
    T delete_pos(int pos);

    void reverse();

    void print();

};


template <typename T>
void dlist<T>::insert_first(T data) {
    node<T>* n = new node<T>(data);

    //list is empty
    if(head == NULL) {
        tail = head = n;
    } else {
        head->prev = n;
        n->next = head;
    head  = n;
    }

}

template <typename T>
void dlist<T>::insert_end(T data) {

    node<T>* n = new node<T>(data);

    //list is empty
	if(tail == NULL) {
        head = tail = n;
	}
	
	else {
        n->prev = tail;
		tail->next = n;
		tail = n; 
	}

}


template <typename T>
void dlist<T>::insert_pos(T data, int pos) {

    node<T>* n = new node<T>(data);

    //list is empty
    if (head == NULL)
    {
        head=tail = n;  
        return;

    } 
    //element is head
    else if (pos == 1) {
        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    else {
        node<T>* cur = head;

        while (cur!= NULL && --pos)
        {
            
            cur = cur->next;
        }

        //reached end of tail
        if (cur == NULL)
        {
            tail->next = n;   
            n->prev = tail;
            tail = n;
        } else {
            
            cur->prev->next = n;
            n->prev = cur->prev;
            cur->prev = n;
            n->next = cur;
        } 

    }

}

template <typename T>
T dlist<T>::delete_first() {
    if(head == NULL ) {
        cout<<"\nNOT ENOUGH ELEMENTS!!!\n";
        return -1;
    }
    node<T>* ptr = head;
    head = head->next;
    
    //if list is empty now
    if(head != NULL) {
        head->prev = NULL;
    }

    T i = ptr->data;
    delete ptr;
    return i;
    
}

template <typename T>
T dlist<T>::delete_last() {
    if(head == NULL ) {
        cout<<"\nNOT ENOUGH ELEMENTS!!!\n";
        return -1;
    }
    node<T>* ptr = tail;
    tail = tail->prev;
    
    //if list is empty now
    if(tail != NULL) {
        tail->next = NULL;
    } else {
        head = tail = NULL;
    }

    T i = ptr->data;
    delete ptr;
    return i;
    
}


template <typename T>
T dlist<T>::delete_pos(int pos) {
    if(head == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return -1;
    }

    node<T> *cur = head;
    while (--pos) 
    {   
        if(cur == NULL) {
            cout<<"UNDERFLOW!!!\n";
            return -1;
        }
        cur = cur->next;
    }

    //deleting element of single element list
    if(cur == head && head == tail) {
        head = tail = NULL;
    }
    
    //deleting head element
    else if (cur == head) {
        head = head->next;
        head->prev = NULL;
    } 
    //deleting tail element
    else if(cur == tail) {

        tail = tail->prev;
        tail->next = NULL;

    }
    
    else {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        
    }

    T i = cur->data;
    
    delete cur;

    return i;
    
}

template <typename T>
void dlist<T> ::reverse() {

    //list has no or only one element
    if (head == NULL || head == tail)
    {
        return;
    }
    node<T> *cur = tail;
    node<T> *temp = NULL;

    while(cur != NULL) {
        temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;

        cur = cur->next;
    }

    temp = head;
    head = tail;
    tail = temp;


}


template<typename T> 
void dlist<T>:: print() {

    if(head == NULL) {
        cout<<"\nLIST IS EMPTY!!!";
        return;
    }
    node<T> *ptr = head;

    cout<<"Your List: ";
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;
    
}


int main() {
    dlist<int> li;

    int ch;

    do {
        cout<<"\n\n\n1. Insert an element at front\n";
        cout<<"\n2. Insert an element at back\n";
        cout<<"\n3. Insert an element at any position\n";
        cout<<"\n4. Delete an element from front\n";
        cout<<"\n5. Delete an element from back\n";
        cout<<"\n6. Delete an element from any position\n";
        cout<<"\n7. Reverse the list\n";
        cout<<"\n8. Print the list\n";
        cout<<"\n\nEnter anything else to EXIT\n";
        cout<<"\nEnter your choice: \n";
        
        cin>>ch;

        switch (ch)
        {
            int e;
            int pos;
        case 1:
            cout<<"\nEnter an element to be inserted: ";
            cin>>e;
            li.insert_first(e);
            li.print();
            break;
        
        case 2:
            cout<<"\nEnter an element to be inserted: ";
            cin>>e;
            li.insert_end(e);
            li.print();
            break;
        
        case 3:
            cout<<"\nEnter an element to be inserted: ";
            cin>>e;
            cout<<"\nEnter position: ";
            cin>>pos;
            li.insert_pos(e, pos);
            li.print();
            break;
        
        case 4:
            li.delete_first();
            li.print();
            break;

        case 5:
            li.delete_last();
            li.print();
            break;

        case 6:
            cout<<"\nEnter position: ";
            cin>>pos;
            li.delete_pos(pos);
            li.print();
            break;
        
        case 7:
            li.reverse();
            li.print();
            break;
        
        case 8:
            li.print();
            break;
        
        default:
            exit(0);
        }
    }while(true);
    

    
}

