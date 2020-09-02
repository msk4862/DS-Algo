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

        void dfs(int cur, int p, int count[]) {
            count[cur]+=1;
            for(auto c: adj[cur]) {
                if(c != p) {
                    dfs(c, cur, count);
                    count[cur] += count[c];
                }
            }
        }
};

int main() { 

    Tree t(6);

    t.addEdge(1, 2);
    t.addEdge(1, 3);
    t.addEdge(2, 4);
    t.addEdge(2, 5);
    t.addEdge(5, 6);
    
    int count[7] = {0};
    t.dfs(1, 0, count);

    for (int i = 1; i <= 6; i++) {
        cout<<count[i]<<" ";
    }

    return 0;
}