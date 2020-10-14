#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
};

Node* findIntersection(Node* head1, Node* head2) {
    int size1 = 0, size2=0;
    
    Node* t = head1;
    while(t) {
        size1++;
        t=t->next;
    }
    t = head2;
    while(t) {
        size2++;
        t=t->next;
    }

    // moving larger list head to common length 
    int diff = abs(size1-size2);
    if(size1 > size2) {
        while(diff) {
            head1 = head1->next;
            diff--;
        }
    }
    else {
        while(diff) {
            head2 = head2->next;
            diff--;
        }
    }

    // finding common node
    while(head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1;
}

int main() {
    return 0;
}