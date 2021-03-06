#include<bits/stdc++.h>
using namespace std;

/*
    Weighted Graph data structure 
    using Adjacency list
*/

template <typename T>
class Graph {
    
    // Adj list
    // "A" -> ("B", 20), ("c", 30), ("D", 46)
    unordered_map<T, list<pair<T, int> > > l; 
    
    public:
        // assuming biderectional edges
        void addEdge(T v1, T v2, bool bider, int weight) {
            l[v1].push_back(make_pair(v2, weight));
            if(bider)
                l[v2].push_back(make_pair(v1, weight));

        }

        void printAdjacencyList() {

            // iterate over all keys of map
            for (auto e: l)
            {
                cout<<"Vertex "<<e.first<<"-> ";
                for(auto nbr : e.second) cout<<"("<<nbr.first<<", "<<nbr.second<<")"<<", ";
                cout<<"\n";
            }
            
        }
};

int main() {
    Graph<string> g;

    g.addEdge("A", "B", true, 40);
    g.addEdge("B", "C", true, 30);
    g.addEdge("B", "D", false, 33);
    g.addEdge("C", "D", true, 29);

    g.printAdjacencyList();
}