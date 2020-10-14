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
        
        if(!t1) return t2;
        if(!t2) return t1;
        
        // just one temp node
        ListNode* res = new ListNode(0);
        ListNode* t = res;
        
        // merging l2 into l1
        while(t1 && t2) {
            if(l1->val < l2->val) {
                t->next = l1;
                t=t->next;
                l1 = l1->next;
            }
            else {
            	t->next = l2;
                t = t->next;
                l2 = l2->next;
            }
        }
        
        if(l1) {
            t->next = l1;
        }
        
        if(l2) {
            t->next = l2;
        }
        
        // 1st elem is temp
        return res->next;
    }


};
