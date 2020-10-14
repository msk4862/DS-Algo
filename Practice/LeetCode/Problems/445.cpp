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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        while(l1 || l2) {
            if(l1) {
                s1.push(l1->val);
                l1=l1->next;
            }
            if(l2) {
                s2.push(l2->val);
                l2=l2->next;
            }
            
        }
        
        int carry=0;
        ListNode* res = nullptr;
        while(!s1.empty() && !s2.empty()) {
            int v1 = s1.top();
            int v2 = s2.top();
            int sum = carry+ v1+v2;
            
            res = new ListNode(sum%10, res);
            
            carry = sum/10;
            s1.pop();
            s2.pop();
        }
        
        if(!s1.empty() || !s2.empty()) {
            
            while(!s1.empty()) {
                int sum = carry + s1.top();
                
                res = new ListNode(sum%10, res);
                s1.pop();
                carry = sum/10;
            }

            while(!s2.empty()) {
                int sum = carry + s2.top();
                
                res = new ListNode(sum%10, res);
                s2.pop();
                carry = sum/10;
            }
        }
        
        if(carry) {
            res = new ListNode(1, res);
        }
        
        return res;
    }
};