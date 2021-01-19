#include<bits/stdc++.h>

// do such (view) questions using tree to 2-d place coordinate system mapping
// with root as (0,0), down the tree: +y, left the root: -x, right the tree: +x 


void dfs(Node* root, map<int, pair<int, int>> &hd_dist, int hd = 0, int depth = 0) {
        if(root == nullptr) return;

        if(hd_dist.count(hd) == 0)
            hd_dist[hd] = make_pair(depth, root->val);
        // we also need to replace with right child val having same hd 
        else if(hd_dist[hd].first <= depth)
            hd_dist[hd] = make_pair(depth, root->val);

        dfs(root->left, hd_dist, hd-1, depth+1);
        dfs(root->right, hd_dist, hd+1, depth+1);
}


void bfs(Node* root, map<int, int> &hd_map) {

    // node, horizontal dist
    queue<pair<Node*, int>> level;
    level.push({root, 0});

    // level order travesal loop
    while(!q.empty()) {
        auto cur = level.front();
        level.pop();
        Node* cur_node = cur.first;
        int hd = cur.second;
        
        // replace node that have same horizontal distance
        // because its at lower pos
        hd_map[hd] = cur_node->val;

        if(cur_node->left) {
            level.push({cur_node->left, hd-1});
        }
        else if(cur_node->right) {
            level.push({cur_node->right, hd+1});
        }
    }

}

void bottomView(Node* root) {

    // horizontal distance, node.val
    map<int, int> hd_dist;

    // using bfs
    bfs(root, hd_dist);

    // horizontal distance, (depth or y-coordinate, node.val)
    map<int, pair<int, int>> &hd_dist1;
    // using dfs
    dfs(root, hd_dist1);

}

