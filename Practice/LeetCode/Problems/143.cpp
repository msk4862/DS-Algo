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
    ListNode* rev(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        
        while(nxt) {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        
        return cur;
    }
    
    void reorderList(ListNode* head) {
        
        // using stack
/*
        if(!head || !head->next || !head->next->next) return;

        ListNode* t = head;
        stack<ListNode*> rev;

        while(t) {
            rev.push(t);
            t=t->next;
        }        
        t = head;
        
        // modifying
        for(int i = rev.size()/2; i > 0; --i) {
            ListNode* nxt = t->next;
            t->next = rev.top();
            t = t->next;
            
            t->next = nxt;

            rev.pop();
            t = t->next;
        }
        t->next=nullptr;
        */
        
        
        // using list reversal
        if(!head || !head->next || !head->next->next) return;

        ListNode* pre = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
                
        // find half
        while(fast && fast->next) {
            pre = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* revH = rev(slow);
        pre->next = nullptr;
        ListNode* t = head;
        while(t) {
            ListNode* nxt = t->next;
            t->next = revH;
            revH=revH->next;

            t = t->next;            
            t->next = nxt;
            
            // last elem
            if(!t->next) {
                t->next = revH;
                break;
            }
            
            t = t->next;
        }
                    
    }
};
