#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* pre;
        Node* next;

        Node(int val) {
            next = pre = nullptr;
            this->val = val;
        }
};


// iterative
Node* reverse(Node* head) {
    if(!head || head->next == nullptr) return head;

    while(cur) {
        Node* next = cur->next;
        cur->next = cur->pre;
        cur->pre = next;

        if(!next) return cur;
        cur = next;
    }

    return cur;
}

// recursive
Node* reverseR(Node* head) {
    if(!head || head->next == nullptr) return head;

    Node* newHead = reverseR(head->next);
    // head->next = tail of revsersed list
    head->next->next = head;
    head->pre = head->next;
    head->next = nullptr;

    return newHead;
}

int main() {
    return 0;
}