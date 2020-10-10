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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* t = head;
        
        ListNode* oddH = nullptr;
        ListNode* to = nullptr;
        
        ListNode* evenH = nullptr;
        ListNode* te = nullptr;

        bool odd = 1;
        while(t) {
            if(odd) {
                if(!oddH) oddH = to = t;
                else {
                    to->next = t;
                    to=to->next;
                }
                odd =0;
            }
            else {
                if(!evenH) evenH = te = t;
                else {
                    te->next = t;
                    te=te->next;
                }
                odd =1;
            }
            t = t->next;
        }
        
        to->next=evenH;
        te->next=nullptr;
        
        return oddH;
        
    }
};


// cleaner code
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
            
        ListNode* oddH = head;
        ListNode* to = oddH;
        
        ListNode* evenH = head->next;
        ListNode* te = evenH;

        while(to && te && to->next && te->next) {
            to->next = to->next->next;
            to = to->next;
            
            te->next = te->next->next;
            te=te->next;
        }
        
        to->next = evenH;
        
        return oddH;
        
    }
};