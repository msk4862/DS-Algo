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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next==nullptr) return head;
        
        ListNode* newHead = reverseList(head->next);
        ListNode* t = newHead;
        while(t->next) {
            t = t->next;
        }
        t->next = head;
        head->next= nullptr;
        
        return newHead;
    }
};