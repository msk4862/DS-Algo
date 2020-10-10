/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head || (!head->next && !head->child)) return head;
        
        Node* p = nullptr;
        Node* n = nullptr;

        if(head->child)
            p = flatten(head->child);
        if(head->next)
            n = flatten(head->next);
        
        
        if(p) {
            
            while(p->next) {
                p=p->next;
            }
            
            p->next = n;
            
            if(n)
                n->prev = p;
            
            head->next = head->child;
            head->child->prev = head;
        }
        else if(n) {
            head->next = n;
            n->prev = head;
        }
        
        head->child = nullptr;
        
        return head;
    }
};