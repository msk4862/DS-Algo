/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        if(!slow) return false;
        ListNode* fast = head->next;
        
        while(slow && fast && fast->next) {
            if(slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};