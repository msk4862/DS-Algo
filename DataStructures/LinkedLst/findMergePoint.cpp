//function to find the merge point of two list

/*
int findMergeNode(Node* head1, Node* head2) {
    SinglyLinkedListNode* head_org1 = head1;
    SinglyLinkedListNode* head_org2 = head2;

    int l1 = getLength(head1), l2 = getLength(head2);
    
    int diff = abs(l1-l2);

    //syncing for longer list
    if(l1 < l2) {
        while (diff!=0) {
            head_org2 = head_org2->next;
            diff--;
        }
    } else if(l1 > l2) {
        while (diff!=0) {
            head_org1 = head_org1->next;
            diff--;
        }
    }
    
    while(head_org1 != head_org2) {
        
            head_org1 = head_org1->next;
            head_org2 = head_org2->next;   

    }

    return head_org1->data;

}
*/