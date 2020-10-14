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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* t = root;
        int n= 0;
        while(t) {
            t=t->next;
            n++;
        }
        
        int pSize = n/k;
        
        // parts > nodes
        if(pSize == 0)
            pSize = 1;
        
        int extra = 0;
        if(n > k) {
            extra = n%k;
        }
        
        int cur= pSize;
        if(extra) {
            cur++;
            extra--;
        }
        
        vector<ListNode*> res;
        ListNode* part = root;
        t=root;
        while(t) {
            cur--;
            if(cur==0) {
                res.push_back(part);
                ListNode* p = t;
                t=t->next;
                p->next = nullptr;

                part = t;
                
                cur = pSize;
                if(extra) {
                    cur++;
                    extra--;
                }
            }
            else {
                t=t->next;
            }
        }
        
        // adding null parts 
        while(res.size() < k) {
            res.push_back(nullptr);
        }
        
        return res;
        
    }
};
