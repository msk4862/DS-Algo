#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

    public:
        Graph(int v) {
            V = v;
            adjList = vector<vector<int>>(v);
        }

        void addEdge(int s, int d) {
            adjList[s].push_back(d);
            adjList[d].push_back(s);
        }
        
        
        bool isCycleHelper(int src, vector<bool> &visited, int parent) {    
            visited[src] = true;

                // cout<<src<<" ";
            for(int adj: adjList[src]) {
                // neighbour is already traversed and not a parent node 
                if(visited[adj] && adj != parent) return true;
                
                if(!visited[adj]) if(isCycleHelper(adj, visited, src)) return true;      
            }

            return false;
        }
        
        bool isCycle() {   
            vector<bool> visited(V, false);

            for(int i = 0; i < V; ++i) {
                if(!visited[i])
                    if(isCycleHelper(i, visited, -1)) return true; 
            }
            return false;
        }
};



int main() {
    Graph g(6);

    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(1, 3); 

    cout<<g.isCycle()<<endl;
    return 0;
}