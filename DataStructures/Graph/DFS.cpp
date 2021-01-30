#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    unordered_map<T, list<T> > l;

    public:
        void addEdge(T s, T d) {
            l[s].push_back(d);
            l[d].push_back(s);
        }
        
        void dfs_recursiveHelper(T src, unordered_map<T, bool> &visited) {
            
            cout<<src<<" ";
            visited[src] = true;

            for(T adj: l[src]) {
                if(!visited[adj]) {
                    dfs_recursiveHelper(adj, visited);        
                }
            }
        }

        void dfs_recursive(T src) {
            unordered_map<T, bool> visited;

            // loop to handle unreachable vertices case
            for(auto vert : l) {
                T node = vert.first;
                if(!visited[node])
                    dfs_recursiveHelper(src, visited);
            }
        }

        void dfs_iterative(T src) {
            stack<T> s;
            unordered_map<T, bool> visited;

            s.push(src);
            visited[src] =true;
            cout<<src<<" ";

            while (!s.empty()) {
                T v = s.top();
                s.pop();

                for(auto nbr : l[v]) {
                    if(!visited[nbr]) {
                        s.push(nbr);
                        visited[nbr] = true;
                        cout<<nbr<<" ";
                    }

                }

            }
            
        }
};

int main() {
    Graph<int> g;

    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.dfs_iterative(2);
    cout<<endl;
    g.dfs_recursive(2);
    cout<<endl;

    return 0;
}