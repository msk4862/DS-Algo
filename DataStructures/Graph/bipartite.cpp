#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<int> *adj;

    public:
    
    Graph(int v) {
        this->v = v;
        adj = new vector<int>[v+1];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool dfs(vector<vector<int>>& graph, int src, vector<int> &color, bool preColor = 1) {
        
        color[src] = preColor ? 1 : 2;
        for(int adj : graph[src]) {
            if(!color[adj]) {
                if(!dfs(graph, adj, color, !preColor)) return false;
            }
            else if(color[adj] == color[src]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        
        for(int i = 0; i < n; ++i)
            if(!color[i])
                if(!dfs(graph, i, color)) return false;
        
        return true;
    }
};

int main() {
    Graph g(5);

    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    if(g.isBipartite()) cout<<"Graph is Bipartite";
    else cout<<"Graph is not Bipartite";

}
