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
class list{
    private:
        node<T> *head;
        node<T> *tail;
    
    public:
        list() {
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
    void serach_and_swap(T elem);

    void print();

};


template <typename T>
void list<T>::insert_first(T data) {
    node<T>* n = new node<T>(data, head);
    head  = n;

    //list is empty
    if(tail == NULL) {
        tail = head;
    }

}

template <typename T>
void list<T>::insert_end(T data) {

    node<T>* n = new node<T>(data);

    //list is empty
	if(tail == NULL) {
        head = tail = n;
	}
	
	else {
		tail->next = n;
		tail = n; 
	}

}


template <typename T>
void list<T>::insert_pos(T data, int pos) {

    node<T>* n = new node<T>(data);

    //list is empty
    if (head == NULL)
    {
        head=tail = n;    

    } 
    //element is head
    else if (pos == 1) {
        n->next = head;
        head = n;
    }

    else {
        node<T>* pre = head;
        node<T>* cur = head;

        while (cur!= NULL && --pos)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = n;
        n->next = cur;

        //reached tail
        if (cur == NULL)
        {
            tail = n;
        }
        

    }

}


template <typename T>
T list<T>::delete_first() {
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!\n";
		return -1;
	}

	else {
		node<T> *ptr = head;
		T i = ptr->data;
		head = ptr->next;
		
		delete ptr;	
		return i;

	}
	
}


template <typename T>
T list<T>::delete_last() {
	if(head == NULL) {
		cout<<"UNDERFLOW!!!!\n";
		return -1;
	}
	
	else {
		node<T> *ptr = head;
		while(ptr->next != tail) {
			ptr = ptr->next;
		}
		
		T i = tail->data;
		tail = ptr;
		tail->next = NULL;
	
		delete ptr->next;
	    return i;	
	}	
}


template <typename T>
T list<T>::delete_pos(int pos) {
    
    node<T> *pre = head;
    node<T> *cur = head;
    while (--pos) 
    {   
        if(cur == NULL) {
            cout<<"UNDERFLOW!!!\n";
            return -1;
        }
        pre = cur;
        cur = cur->next;
    }
    
    //deleting head element
    if (cur == head) {
        head = head->next;
    } 
    //deleting tail element
    else if(cur == tail) {
        tail = pre;
        tail->next = NULL;
    }

    else {
        pre->next = cur->next;

    }   

    T i = cur->data;
    
    
    delete cur;

    return i;
    
}

template <typename T>
void list<T> ::reverse() {

    //list has no or only one element
    if (head == NULL || head == tail)
    {
        return;
    }
    //list has only two elements
    else if(head->next == tail) {
        tail->next = head;
        head->next = NULL;

        head = tail;
        tail = tail->next;
        return;

    }

    
    node<T> *pre = head;
    node<T> *cur = pre->next;
    node<T> *after = cur->next;


    while (after != tail)
    {   
        cur->next = pre;
        pre = cur;
        cur = after;
        after = after->next;

    }

    cur->next = pre;
    after->next = cur;

    head->next = NULL;
    tail = head;
    head = after;

}

template <typename T>
void list<T> ::serach_and_swap(T elem) {

    if(head == NULL || head == tail || head ->data == elem) {
        cout<<"INVALID INPUT!!!\n";
        return;
    } 
    //list has only two elements
    else if(head->next == tail) {
        tail->next = head;
        head = tail;
        tail = tail->next;

        return;
    }

    node<T> *pre_pre = head;
    node<T> *pre = head->next;
    node<T> *cur = pre->next;

    //given element is at second position 
    if(pre->data == elem) {
        pre_pre->next = pre->next;
        pre->next = pre_pre;
        head = pre;

        return;
    }


    bool found = false;
    while(cur!=NULL) {
        
        if(cur->data == elem) {
            found = true;
            break;
        }
        pre_pre = pre;
        pre = cur;
        cur = cur->next;
    }
    if(found) {

        pre_pre->next = cur;
        pre->next = cur->next;
        cur->next = pre;

        //swapped element is tail
        if(cur == tail) {
            tail = pre;
        }
        
    } else {
        cout<<"ELEMENT NOT FOUND!!!\n";
    }
}

template<typename T> 
void list<T>:: print() {
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
    list<char> li;

    li.insert_first('a');
    li.print();
    li.insert_end('d');
    li.print();
    li.insert_pos('v', 2);
    li.print();

    
    li.insert_pos('k', 1);
    li.print();

    li.insert_pos('l', 3);
    li.print();

    li.delete_first();
    li.print();


    li.delete_pos(3);
    li.print();

    li.reverse();
    li.print();

    li.insert_pos('h', 2);
    li.print();

    li.serach_and_swap('a');
    li.print();
}
