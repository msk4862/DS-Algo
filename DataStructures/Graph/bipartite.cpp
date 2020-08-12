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

    bool dfs(int v, bool visited[], bool color[], bool pre=0) {
        visited[v] = 1;
        color[v] = pre?0:1;

        for(int ad:adj[v]) {
            if(!visited[ad])
               return dfs(ad, visited, color, color[v]);
            else
                if(color[v] == color[ad]) 
                    return false;
        }

        return true;
    }

    bool isBipartite() {
        bool visited[v+1];
        bool color[v+1];

        return dfs(1, visited, color);

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