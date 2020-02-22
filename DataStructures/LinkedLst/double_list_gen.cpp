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
T dlist<T>::delete_pos(int pos) {
    
    node<T> *cur = head;
    while (--pos) 
    {   
        if(cur == NULL) {
            cout<<"UNDERFLOW!!!\n";
            return -1;
        }
        cur = cur->next;
    }
    
    //deleting head element
    if (cur == head) {
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
    dlist<char> li;

    li.insert_first('a');
    li.print();
    li.insert_end('d');
    li.print();
    
    
    li.insert_end('o');
    li.print();
    
    
    li.insert_first('r');
    li.print();
    li.insert_pos('v', 5);
    li.print();

    
    li.insert_pos('k', 1);
    li.print();

    li.insert_pos('l', 3);
    li.print();

    li.delete_pos(3);
    li.print();

}
