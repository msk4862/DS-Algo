#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
};

Node* pairWiseSwap(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* pre = nullptr;
    Node* p1=head;
    Node* p2=head->next;

    // updating head & its adjacent
    head = p2;
    head->next = p1;

    while(true) {
        p1->next=p2->next;
        p2->next = p1;            
        pre->next = p2;

        // another pair is remaining
        if(p1->next == nullptr or p1->next->next) break;

        pre = p1;
        p1 = p1->next;
        p2 = p1->next;
    }

    return head;

}

int main() {
    return 0;
}