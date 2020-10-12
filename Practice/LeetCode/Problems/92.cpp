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
    ListNode* reverse(ListNode* h) {
        if(!h || !h->next) return h;
        
        ListNode* newH = reverse(h->next);
        h->next->next = h;
        h->next = nullptr;
        return newH;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int pos = 1;
        
        ListNode* t = head;
        ListNode* start = nullptr;
        ListNode* end = nullptr;;
        ListNode* prev = nullptr;

        ListNode* revH = nullptr;
        
        while(t) {
            if(pos == m) {
                start = prev;
                revH = t;
            }
            if(pos == n) {
                end = t->next;
                t->next = nullptr;
                break;
            }
            prev = t;
            t =t->next;
            pos++;
        }
        
        if(start)
            start->next = reverse(revH);
        // m == 1
        else
            head = reverse(revH);
        
        // last elem of revrsed list
        revH->next=end;
            
        return head;
    }
};
