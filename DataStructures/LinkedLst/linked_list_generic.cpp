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
        if(head == tail) {
            T i = head->data;
            delete head;
            head = tail = NULL;
            return i;
        }
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
    if(head == NULL) {
        cout<<"UNDERFLOW!!!\n";
        return -1;
    }
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
        cout<<"INVALID ELEMENT GIVEN!!!\n";
        return;
    } 
    //list has only two elements
    else if(head->next == tail) {
        tail->next = head;
        head = tail;
        tail = tail->next;
        tail->next = NULL;

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
    
    if(head == NULL) {
        cout<<"LIST IS EMPTY!!!";
        return;
    }

    node<T> *ptr = head;


    cout<<"\nYour List: ";
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

    cout<<endl;
    
}


int main() {
    list<int> li;

    int ch;

    do {
        cout<<"\n\n\n1. Insert an element at front\n";
        cout<<"\n2. Insert an element at back\n";
        cout<<"\n3. Insert an element at any position\n";
        cout<<"\n4. Delete an element from front\n";
        cout<<"\n5. Delete an element from back\n";
        cout<<"\n6. Delete an element from any position\n";
        cout<<"\n7. Reverse the list\n";
        cout<<"\n8. Search and swap an element\n";
        cout<<"\n9. Print the list\n";
        cout<<"\nEnter -1 to EXIT\n";
        cout<<"\nEnter your choice: \n";
        
        cin>>ch;

        switch (ch)
        {
            int e, pos;
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
            cout<<"\nEnter the element to be searched: ";
            cin>>e;
            li.serach_and_swap(e);
            li.print();
            break;
        
        case 9:
            li.print();
            break;
        
        default:
            cout<<"\nINVALID CHOICE!!!\n";
        }
    }while(ch != -1);
    

    
}
