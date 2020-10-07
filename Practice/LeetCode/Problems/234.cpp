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
    ListNode* reverse(ListNode* n) {
        if(!n || !n->next) return n;
        
        ListNode* newhead = reverse(n->next);
        
        // points to revrsed list tail
        n->next->next = n;
        n->next = nullptr;
        
        return newhead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // slow will reach at half
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* half = reverse(slow);
        
        while(head && half) {
            if(head->val != half->val) return false;
            head=head->next;
            half=half->next;
        }
        
        return true;
    }
};