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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        
        // maintain a gap of n elem between fast and slow 
        for(int i =0; i < n; ++i) {
            fast=fast->next;
        }
        
        // when fast is null then slow will be at nth from last
        while(fast) {
            pre = slow;
            slow=slow->next;
            fast=fast->next;
        }
        
        if(pre)
            pre->next = slow->next;
        else
            head = slow->next;
        
        return head;
    }
    
};
