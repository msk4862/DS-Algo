#include<bits/stdc++.h>

void getVerticalOrder(Node* root, int hd, int l, map<int, pair<int, int>> &hd_map) {
        if(root == nullptr) return;

        if(hd_map.count(hd) == 0)
            hd_map[hd] = make_pair(root->data, l);
        else if(l < hd_map[hd].second)
            hd_map[hd] = make_pair(root->data, l);

        getVerticalOrder(root->left, hd-1, l+1, hd_map);
        getVerticalOrder(root->right, hd+1, l+1, hd_map);
}



void topView(Node* root) {

    // horizontal distance -> (node.val, level)
    map<int, pair<int, int>> hd_map;

    getVerticalOrder(root, 0, 1, hd_map);


    for(auto line: hd_map) {
        cout<<line.second.first<<" ";
}

