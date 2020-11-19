#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* down;
        Node* next;

        Node(int val) {
            next = down = nullptr;
            this->val = val;
        }
};

Node* merge(Node* head1, Node* head2) {
    Node* merged = new Node(-1);

    while(head1 && head2) {
        if(head1->val < head2->val) {
            merged->next = head1;
            head1=head1->next;
        }
        else {
            merged->next = head2;
            head2=head2->next;
        }
    }

    if(head1) merged->next = head1;
    if(head2) merged->next = head2;
    
    return merged->next;
}

Node* flatten(Node* head) {
    if(head->next == nullptr) return head;

    // merge sorted lists
    return merge(head, flatten(head->next));
}

int main() {
    return 0;
}