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
    
    // SEE EDGE CASES 
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* tail=nullptr; 
        ListNode* pre = nullptr;
    
        int size = 0;
        
        // maintain a gap of n elem between fast and slow 
        for(int i =0; i < k; ++i) {
            size++;
            tail = fast;
            fast=fast->next;
            
            // if k > size
            if(!fast) {
                tail=nullptr;
                fast = head;
                
                // initialize after normalizing rotation numbers (k)
                k=k%size;
                
                // k was = size of list
                if(k==0) return head;
                
                i=-1;
                
            } 
        }
        
        // when fast is null then slow will be at nth from last
        while(fast) {
            tail = fast;
            pre = slow;
            slow=slow->next;
            fast=fast->next;
        }
                
        tail->next = head;
        pre->next = nullptr;
        head =slow;
        
        return head;
    }
};
