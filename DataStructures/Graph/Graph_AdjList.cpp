#include<bits/stdc++.h>
using namespace std;

/*
    Graph data structure 
    using Adjacency list
*/

class Graph {
    public:
    int V;
    unordered_map<int, list<int>> l; 
    /*
        If vecrtices are numeric values from 1 to N
        we can use simply use array of list i.e. list<int> *l; 
    */
    Graph(int V) {
        this->V = V;
        // l = new list<int>[V];
    }

    // assuming biderectional edges
    void addEdge(int v1, int v2) {
        l[v1].push_back(v2);
        l[v2].push_back(v1);
    }

    void printAdjacencyList() {
        for (auto e: l)
        {
            cout<<"Vertex "<<e.first<<"-> ";
            for(auto nbr : e.second) cout<<nbr<<" ";
            cout<<"\n";
        }
        
    }
};

int main() {
    Graph g(4);

    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.printAdjacencyList();
}