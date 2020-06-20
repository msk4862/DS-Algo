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
    ListNode* middleNode(ListNode* head) {
        ListNode* t = head;
        int length = 0, mid;
        while(t!=nullptr) {
            length++;
            t = t->next;
        }
        
        if(length%2 == 0 ) mid = length/2 + 1;
        else mid = ceil(length/2.0);
                // cout<<length<<" "<<mid<<"\n";

        t = head;
        while(mid!=1) {
            t = t->next;
            mid-=1;
        }
        
        return t;
    }
};