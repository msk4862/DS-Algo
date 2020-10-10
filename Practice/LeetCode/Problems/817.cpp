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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int , bool> m;
        for(auto e: G) {
            m[e] =1;
        }
        
        int res = 0;
        bool start=0;
        while(head) {
            if(m[head->val]) {
                start =1;
            }
            else {
                if(start) {
                    start =0;
                    res++;
                }
            }
            head=head->next;
        }
        
        if(start) res++;
        
        return res;
    }

};