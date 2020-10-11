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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);

        ListNode* pre = head;                
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        // finding half
        while(slow && fast && fast->next) {
            pre = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        cout<<slow->val<<" ";
        TreeNode* root= new TreeNode(slow->val);
        ListNode* half = slow->next;        
        
        // partitioning list
        
        // only two elements were there
        if(pre == slow)
            head = nullptr;
        else 
            pre->next = nullptr;
        
        root->left = constructBST(head);
        root->right = constructBST(half);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        
        return constructBST(head);
    }
};
