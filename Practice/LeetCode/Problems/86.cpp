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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-1);
        ListNode* rest = new ListNode(-1);
        
        ListNode* tl = less;
        ListNode* tr = rest;
        
        while(head) {
            if(head->val < x) {
                tl->next = head;
                tl = tl->next;
            }
            else {
                tr->next = head;
                tr=tr->next;
            }
            head=head->next;
        }
        
        // first is dummy
        tl->next = rest->next;
        tr->next = nullptr;
        
        return less->next;
        
    }
};
