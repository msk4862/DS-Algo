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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        // temp headss
        ListNode* tHead = new ListNode(0);
        ListNode* cur = head;
        
        while(cur) {
            ListNode* next = cur->next;
            ListNode* prev = tHead;
            
            while(prev->next && prev->next->val <= cur->val) {
                prev = prev->next;
            }
            
            ListNode* t = prev->next;
            prev->next = cur;
            cur->next = t;
            prev = tHead;
            cur=next;
        }
        return tHead->next;
    }
};
