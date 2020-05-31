//function to insert a node in sorted lisr

/*
DoublyLinkedListNode<int> sortedInsert(DoublyLinkedListNode<int> head, int data) {
    
    DoublyLinkedListNode* n = new DoublyLinkedListNode(data);

    if(head==nullptr) {
        head = n;
    }
    DoublyLinkedListNode* p = head;
    DoublyLinkedListNode* t;

    //head
    if(p->data >= data) {
        n->next=p;
        p->prev=n;
        head=n;
    }
    
    while(p->next!=nullptr) {
        if(p->data >= data) {
            t = p->prev;
            t->next = n;
            n->prev=t;
            n->next = p;
            p->prev = n;
            
            return head;
        }
        p=p->next;
    }

    if(p->data >= data) {
        t = p->prev;
        t->next = n;
        n->prev=t;
        n->next = p;
        p->prev = n;
    } else {
        //at tail
        p->next = n;
        n->prev = p;
    }

    return head;

}
*/