#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FASTIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr); \
    cout.tie(nullptr);


class Tree {
    vector<int> *adj;

    public:
        Tree(int v) {
            adj = new vector<int>[v+1];
        }

        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void toLeaf(int n, int p, int toLeafDist[]) {
            int max_d = INT_MIN;
            for(auto c : adj[n]) {
                if(c!=p) {
                    toLeaf(c, n, toLeafDist);
                    max_d = max(max_d, toLeafDist[c]);
                }
            }
            if(max_d != INT_MIN)
                toLeafDist[n] = max_d +1; 
        }
};

int main() { 

    int v = 7;
    Tree t(v);

    t.addEdge(1, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);
    t.addEdge(2, 5);
    t.addEdge(2, 6);
    t.addEdge(4, 7);
    
    int toLeafDist[v+1] = {0};

    t.toLeaf(1, 0, toLeafDist);

    for (int i = 1; i <= v; i++) {
        cout<<toLeafDist[i]<<" ";
    }

    return 0;
}