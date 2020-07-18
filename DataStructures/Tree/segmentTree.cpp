#include<bits/stdc++.h>
using namespace std;

void buildTree(int* tree, int* elem, int index, int s, int e) {
    // Base Case
    if(s > e) return;

    // Base cases
    if(s==e) {
        tree[index] = elem[s];
        return;
    }
    
    int mid = (e-s)/2 + s;
    // build left subtree
    buildTree(tree, elem, 2*index, s, mid);
    // build right subtree
    buildTree(tree, elem, 2*index+1, mid+1, e);

    tree[index] = min(tree[2*index], tree[2*index+1]);

}

// return minimum element in range qs and qe
int query(int *tree, int index, int s, int e, int qs, int qe) {
    // 1. no overlap
    if(qe < s or e < qs) 
        return INT_MAX;
    
    // 2. complete overlap
    if(s >= qs and e <= qe)
        return tree[index];

    // 3. paritial overlap
    int mid = (e-s)/2 + s;
    int leftAns = query(tree, 2*index, s, mid, qs, qe);
    int rightAns = query(tree, 2*index+1, mid+1, e, qs, qe);

    return min(leftAns, rightAns);
}


// update value of a node 
void node_update(int* tree, int index, int s, int e, int updateIndex, int value) {
    // 1. no overlap
    if(updateIndex < s or e < updateIndex) 
        return;
    
    // 2. complete overlap (leaf node)
    if(s==e) {
        tree[index] = value;
        return;
    }

    // 3. updateIndex lying in range s and e
    int mid = (e-s)/2 + s;
    node_update(tree, 2*index, s, mid, updateIndex, value);
    node_update(tree, 2*index+1, mid+1, e, updateIndex, value);

    tree[index] = min(tree[2*index], tree[2*index+1]);
}


// Range Update
// increment values of array lying in range rs and re by a value v
void range_update(int* tree, int index, int s, int e, int rs, int re, int v) {
    // 1. no overlap
    if(re < s or e < rs) 
        return;
    
    // 2. complete overlap (leaf node)
    if(s == e) {
        tree[index] += v;
        return;
    }

    // 3. updateIndex lying in range s and e
    int mid = (e-s)/2 + s;
    range_update(tree, 2*index, s, mid, rs, re, v);
    range_update(tree, 2*index+1, mid+1, e, rs, re, v);

    tree[index] = min(tree[2*index], tree[2*index+1]);
}



// Program to find min element in a range 
int main() {
    int ar[] = {1,3,2,-2,4,5};
    int n = sizeof(ar)/sizeof(int);

    // build tree array 
    // max size = 4*n+1 (inedex starting from 1)
    int* tree = new int[4*n+1];
    memset(tree, -1, sizeof(tree));

    buildTree(tree, ar, 1, 0, n-1);
    for (int i = 1; i < 4*n+1; i++) {
        cout<<tree[i]<<" ";
    }


    // Node Update
    int i, v;
    cout<<"\nEnter index and value to be updated: ";
    cin>>i>>v;

    node_update(tree, 1, 0, n-1, i, v);
    for (int i = 1; i < 4*n+1; i++) {
        cout<<tree[i]<<" ";
    }
    

    // Range Update
    int rs, re, change;
    cout<<"\nEnter range and value to be updated: ";
    cin>>rs>>re>>change;

    range_update(tree, 1, 0, n-1, rs, re, change);
    for (int i = 1; i < 4*n+1; i++) {
        cout<<tree[i]<<" ";
    }
    

    cout<<endl;

    int q;
    cin>>q;

    // making queries
    int qs, qe;
    while(q--) {
        cin>>qs>>qe;
        cout<<query(tree, 1, 0, n-1, qs, qe)<<"\n";
    }

    return 0;
}