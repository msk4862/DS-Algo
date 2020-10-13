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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t = head;
        ListNode* pre = nullptr;
        
        while(t && t->next) {
            if(t->val == t->next->val) {
                int dup = t->val;
                while(t && t->val==dup) {
                    t=t->next;
                }
                
                if(pre)
                    pre->next = t;
                else
                    head = t;
            }
            else {
                pre = t;
                t=t->next;
            }
        }
        
        return head;
    }
};
