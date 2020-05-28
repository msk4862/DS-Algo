bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while(fast->next && fast->next->next) {
        if(fast == slow) {
            return true;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
    }
return false;

}