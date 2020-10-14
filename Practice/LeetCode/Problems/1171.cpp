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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m;
        
        ListNode* t = head;
        
        int sum = 0;
        while(t) {
            sum += t->val;
            if(m[sum]) {

                // remove sums from map
                ListNode* rt = m[sum]->next;
                int p = sum;
                while(rt && rt != t) {
                    p+=rt->val;
                    m.erase(p);
                    rt=rt->next;
                }
                
                // update links to remove subset
                m[sum]->next=t->next;
                t = m[sum];
            }
            // start from beginning
            else if(sum == 0) {
                head=t->next;
                m.clear();
            }
            else {
                m[sum] = t;
            }
            t=t->next;
        }
        
        return head;
    }
};
