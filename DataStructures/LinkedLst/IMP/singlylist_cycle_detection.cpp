// other approach is Hashing with O(n) space complexity

bool has_cycle(SinglyLinkedListNode* head) {
     if(head==nullptr) {
        return false;
    }

    SinglyLinkedListNode* slow = head;
    SinglyLinkedListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            return true;
        }
    }

return false;


}