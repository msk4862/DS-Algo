#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
    map<T, list<T> > l;

    public:
        void addEdge(T s, T d) {
            l[s].push_back(d);
            l[d].push_back(s);
        }
        
        void traverse(T src, map<T, bool> &visited) {
            cout<<src<<", ";

            for(auto nbr:l[src])
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    traverse(nbr, visited);
                }
        }

        // without stack
        void dfs_rec(T src) {
            map<T, bool> visited;

            // marking all vertices false
            for(pair<T, list<T> > v:l) 
                visited[v.first] = false;
            
            visited[src] = true;
            traverse(src, visited);
        }
        
        // usin stack;
        void dfs(T src) {
            stack<T> s;
            map<T, bool> visited;

            s.push(src);
            visited[src] =true;

            while (!s.empty()) {
                T v = s.top();
                s.pop();

                for(auto nbr:l[v]) {
                    if(!visited[nbr]) {
                        s.push(nbr);
                        visited[nbr] = true;
                    }

                }

                cout<<v<<" ";
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

    g.dfs(2);
    cout<<"\n";
    g.dfs_rec(2);

    return 0;
}