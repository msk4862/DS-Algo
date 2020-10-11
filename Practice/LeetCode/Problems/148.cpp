/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
                
        ListNode* n;
        if(l1->val < l2->val) {
            n = l1;
            n->next = merge(l1->next, l2);
        }
        else {
            n = l2;
            n->next = merge(l1, l2->next);
        }
        return n;

    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            prev = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // divide into two lists
        prev->next = nullptr;        

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return merge(l1, l2);
    }
};
