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
        }
        
        
        bool isCycleHelper(int src, vector<bool> &visited,vector<bool> &in_stack) {    
            visited[src] = in_stack[src] = true;
            for(int adj: adjList[src]) {
                if(in_stack[adj]) return true;
                if(!visited[adj]) 
                    if(isCycleHelper(adj, visited, in_stack)) return true;      
            }
            
            // visited all adjacent nodes of src recusively
            // and no cycle found
            // removing src from stack
            in_stack[src] = false;
            return false;
        }
        
        bool isCycle() {            
            vector<bool> visited(V, false);
            // if its in current path
            // for cases like 1->2<-3
            vector<bool> in_stack(V, false);
            
            for(int i = 0; i < V; ++i) {
                if(!visited[i]) {
                    // for each connected component 
                    if(isCycleHelper(i, visited, in_stack)) return true; 
                }
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

    cout<<g.isCycle();

    return 0;
}