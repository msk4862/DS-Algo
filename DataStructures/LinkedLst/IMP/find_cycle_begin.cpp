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
        //Method 1 - slow and fast pointer
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        
        bool found = 0;
                
        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) {
                found=1;
                break;
            }
        }
        
        // no loop
        if(!found) return nullptr;
        
        // starting from begin
        slow = head;
        while(slow != fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    
    // Method 2- Modifying list
    ListNode *detectCycle(ListNode *head) {
		ListNode* visited = new ListNode(-1);
		
		while(head) {
			if(head->next == visited) {
				return head;
			}
			ListNode* t = head->next;
			head->next = visited;
			
			head = head->next;
		}
		
		return nullptr;
	}
};
