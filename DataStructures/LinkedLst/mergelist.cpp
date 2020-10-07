Merge two list

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

    // recursive
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* n;
        if(l1->val < l2->val) {
            n = l1;
            n->next = mergeTwoLists(l1->next, l2);
        } else {
            n = l2;
            n->next = mergeTwoLists(l1, l2->next);
        }
        
        return n;

    }
    

    // iterative
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        if(!t1) return t2;
        if(!t2) return t1;
        
        ListNode* prev = nullptr;
        
        // merging l2 into l1
        while(t1 && t2) {
            if(t1->val == t2->val) {
                t1->next = new ListNode(t2->val, t1->next);
                
                prev = t1->next;
                t1 = t1->next->next;
                t2 = t2->next;
            } 
            else if(t1->val < t2->val) {
                prev = t1;
                t1 = t1->next;
            }
            else {
                // if previous is null 
                if(!prev) {
                    l1 = prev = new ListNode(t2->val, t1); 
                }
                else {
                    prev->next = new ListNode(t2->val, prev->next);
                    prev = prev->next;
                }
                t2 = t2->next;
            }
        }
        
        if(t2) {
            prev->next = t2;
        }
        
        return l1;
    }


};