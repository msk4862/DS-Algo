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

    void dfs(int v, bool visited[]) {

        visited[v] = 1;
        cout<<v<<" "; 
        for (int ad:adj[v]) {   
            if(!visited[ad])
                dfs(ad, visited);
        }
    }

    bool isConnected() {
        bool visited[v+1] = {0};

        dfs(1, visited);

        for(int i = 1; i <= v; ++i) if(visited[v] == 0) return 0;

        return 1;
    }

};

int main() {
    Graph g(5);

    g.addEdge(1, 3);
    g.addEdge(4, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 1);

    if(g.isConnected()) cout<<"Graph is Connected";
    else cout<<"Graph is not connected";
    
}